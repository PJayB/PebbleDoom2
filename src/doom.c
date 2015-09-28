#include <pebble.h>
#include "doom.h"
#include "prezr.h"
#include "prezrpackages.h"
#include "packhelpers.h"
#include "spritehelpers.h"
#include "doom_ui.h"
#include "doom_anim.h"

// Global state
uint8_t batteryPercent = 100;
bool batteryCharging = false;
bool bluetoothState = false;
bool walking = true;
bool can_start_new_anim = true;

// Destructor
static void handle_window_unload(Window* window) {
    doom_destroy_ui();
    unload_resources();
}

// Constructor
void doom_init(struct tm* init_time, uint8_t batteryPercent, bool isCharging, bool hasBluetooth) {
    // Load resources
    doom_initialise_ui();
    load_resources();

    // Fire event handlers and set initial state
    set_time_display(init_time);
    set_battery_status(batteryPercent, isCharging);
    set_bluetooth_status(hasBluetooth);

    // Set walk animation
    start_zombie_walk_anim();
    start_weapon_static_anim();

    window_set_window_handlers(s_window, (WindowHandlers) {
        .unload = handle_window_unload,
    });
    window_stack_push(s_window, true);
}

void doom_destroy(void) {
    window_stack_remove(s_window, true);
}

//
// Status tracking internal APIs
//

void set_time_display(struct tm* t) {
    bool is_24h = clock_is_24h_style();
    int hour = t->tm_hour;

    if (!is_24h) {
        if (hour == 0)
            hour = 12;
        else if (hour > 12)
            hour -= 12;
    }

    if (is_24h || hour > 9) {
        // two numbers here
        layer_set_hidden(bitmap_layer_get_layer(num0), false);
        bitmap_layer_set_bitmap(num0, prezr_numerals.resources[hour / 10].bitmap);
    }
    else {
        // single digit
        layer_set_hidden(bitmap_layer_get_layer(num0), true);
    }

    bitmap_layer_set_bitmap(num1, prezr_numerals.resources[hour % 10].bitmap);
    bitmap_layer_set_bitmap(num2, prezr_numerals.resources[t->tm_min / 10].bitmap);
    bitmap_layer_set_bitmap(num3, prezr_numerals.resources[t->tm_min % 10].bitmap);
}

void set_battery_status(uint8_t percent, bool charging) {
    batteryCharging = charging;
    batteryPercent = percent;

    start_face_anim(batteryPercent, batteryCharging);
}

void set_bluetooth_status(bool hasBluetooth) {
    if (bluetoothState == hasBluetooth) {
        return;
    }

    bluetoothState = hasBluetooth;
    start_lamp_anim(hasBluetooth);
}

//
// Animation internal
//

static const int fire_frame_delay = 200;
static const int die_frame_delay = 200;
static const int respawn_frame_delay = 200;
static const int respawn_pause = 3000;

void respawn_frame(size_t frameNum) {
    if (at_end_of_respawn_anim(frameNum)) {
        // end of animation - end respawn
        end_respawn_anim();

        // end of entire animation
        can_start_new_anim = true;
    }
    else {
        // continue the animation
        animate_respawn(++frameNum);

        // kick off the next frame timer
        app_timer_register(
            respawn_frame_delay,
            (AppTimerCallback) respawn_frame,
            (void*) frameNum);
    }
}

void respawn(void) {
    end_zombie_die_anim();

    // Start walking animation
    start_zombie_walk_anim();
    walking = true;

    // Start the respawn animation
    start_respawn_anim();

    // Animate the next frame
    app_timer_register(
        respawn_frame_delay,
        (AppTimerCallback) respawn_frame,
        (void*) 0);
}

void die_frame(size_t frameNum) {
    if (at_end_of_zombie_die_anim(frameNum)) {
        // end of animation - start respawn
        app_timer_register(
            respawn_pause,
            (AppTimerCallback) respawn,
            NULL);
    }
    else {
        // continue the animation
        animate_zombie_die(++frameNum);

        app_timer_register(
            die_frame_delay,
            (AppTimerCallback) die_frame,
            (void*) frameNum);
    }
}

// Second phase of fire animation
void fire_frame2(size_t frameNum) {
    if (at_end_of_weapon_fire_anim(frameNum)) {
        // switch back to static
        end_weapon_fire_anim();
        start_weapon_static_anim();
    } else {
        animate_weapon_fire(++frameNum);
        
        // Set next frame timer
        app_timer_register(
            fire_frame_delay,
            (AppTimerCallback) fire_frame2,
            (void*) frameNum);
    }
}

void fire_frame(void* unused) {
    hide_muzzle_flash_anim();
    start_weapon_fire_anim();

    app_timer_register(
        fire_frame_delay,
        (AppTimerCallback) fire_frame2,
        (void*) 0);
}

//
// Animation API
//

void doom_play_kill_animation(void) {
    if (can_start_new_anim) {
        // don't allow other animation requests to interrupt us
        walking = false;
        can_start_new_anim = false;

        // evict the walk animation and load the die animation
        stop_zombie_walk_anim();
        start_zombie_die();

        // show muzzleflash
        show_muzzle_flash_anim();

        // start firing timer
        app_timer_register(
            fire_frame_delay,
            (AppTimerCallback) fire_frame,
            NULL);

        // start firing timer
        app_timer_register(
            die_frame_delay,
            (AppTimerCallback) die_frame,
            (void*) 0);
    }
}

void doom_animate(void) {
    animate_face(batteryPercent, batteryCharging);

    if (walking) {
        animate_zombie_walk();
    }
}

//
// Status indicator APIs
//

void doom_time_changed(struct tm *t) {
    set_time_display(t);
}

void doom_battery_level_changed(uint8_t percent, bool charging) {
    set_battery_status(percent, charging);
}

void doom_bluetooth_changed(bool connected) {
    set_bluetooth_status(connected);
}
