#include <pebble.h>
#include "doom.h"
#include "prezr.h"
#include "prezrpackages.h"
#include "packhelpers.h"
#include "spritehelpers.h"
#include "doom_ui.h"

#define countof(x) (sizeof(x)/sizeof(x[0]))

// Global state
int face_index = 0;
uint8_t batteryPercent = 100;
bool batteryCharging = false;
bool bluetoothState = false;
bool walking = true;
bool can_start_new_anim = true;
int walk_frame = 0;
 
// Layout constants
static GPoint enemyPos = { 48+25, 18+56 };
static GPoint weaponPos = { 69, 136 };
static GPoint respawnPos = { 48+25, 18+28 };

// Placement memory for animating/frequently changing sprites
placement_block_t weapon_mem = { NULL };
placement_block_t zombie_mem = { NULL };

// Static packs
prezr_pack_t background_pack = prezr_pack_default;
prezr_pack_t numeric_pack = prezr_pack_default;

// Infrequently changing packs
prezr_pack_t lamp_pack = prezr_pack_default;
prezr_pack_t face_pack = prezr_pack_default;

// Dynamic packs (frequently changing)
prezr_pack_t weapon_pack = prezr_pack_default;
prezr_pack_t zombie_pack = prezr_pack_default;
prezr_pack_t respawn_pack = prezr_pack_default;
size_t respawn_mem_offset = 0;

void set_time_display(struct tm* t);
void set_battery_status(uint8_t percent, bool charging);
void set_bluetooth_status(bool hasBluetooth);
void load_zombie_walk(void);
void load_sg_static(void);

// Initialize the resources that never change
void init_static_resources(void) {
  load_pack(&background_pack, RESOURCE_ID_PREZR_BACKGROUND_PACK);
  load_pack(&numeric_pack, RESOURCE_ID_PREZR_NUMERIC_PACK);

  bitmap_layer_set_bitmap(layer_level_bg, prezr_background.resources[PREZR_BACKGROUND_BACKGROUND].bitmap);
  bitmap_layer_set_bitmap(layer_statusbar_bg, prezr_background.resources[PREZR_BACKGROUND_STATUSBAR].bitmap);
}
void destroy_static_resources(void) {
    prezr_destroy(&background_pack);
    prezr_destroy(&numeric_pack);
}

// Initialization of dynamic resources is done on-the-fly. This just does cleanup.
void init_dynamic_resources(void) {
    // Remember where the respawn animation goes inside the placement buffer
    respawn_mem_offset = get_resource_size(RESOURCE_ID_PREZR_ZOMBIEWALK_PACK);

    size_t zombie_resource_sizes[] = {
        // Walk and respawn must be co-resident, but zombie die is standalone
        respawn_mem_offset + get_resource_size(RESOURCE_ID_PREZR_RESPAWN_PACK),
        get_resource_size(RESOURCE_ID_PREZR_ZOMBIEDIE_PACK)
    };

    size_t weapon_resource_sizes[] = {
        get_resource_size(RESOURCE_ID_SG_STATIC_PACK),
        get_resource_size(RESOURCE_ID_SG_FIRE1_PACK),
        get_resource_size(RESOURCE_ID_SG_FIRE2_PACK),
        get_resource_size(RESOURCE_ID_SG_FIRE3_PACK)
    };

    // Allocate the memory for the animations
    init_shared_placement_block(&zombie_mem, zombie_resource_sizes, countof(zombie_resource_sizes));
    init_shared_placement_block(&weapon_mem, weapon_resource_sizes, countof(weapon_resource_sizes));

    // Set up the default state
    load_zombie_walk();
    load_sg_static();
}
void destroy_dynamic_resources(void) {
    // Infrequently changing packs
    prezr_destroy(&lamp_pack);
    prezr_destroy(&face_pack);

    // Frequently changing
    prezr_placement_destroy(&respawn_pack);
    prezr_placement_destroy(&weapon_pack);
    prezr_placement_destroy(&zombie_pack);

    // Placement buffers
    destroy_shared_placement_block(&weapon_mem);
    destroy_shared_placement_block(&zombie_mem);
}

// Destructor
static void handle_window_unload(Window* window) {
  doom_destroy_ui();
  
  // delete images
  destroy_static_resources();
  destroy_dynamic_resources();
}

// Shorthand APIs for switching animations
void load_zombie_walk(void) {
    load_placement_pack(&zombie_pack, &zombie_mem, RESOURCE_ID_PREZR_ZOMBIEWALK_PACK);
    set_image_and_center_bottom(layer_player, &zombie_pack.resources[0], zombiePos);
}
void load_zombie_die(void) {
    load_placement_pack(&zombie_pack, &zombie_mem, RESOURCE_ID_PREZR_ZOMBIEDIE_PACK);
    set_image_and_center_bottom(layer_player, &zombie_pack.resources[0], zombiePos);
}

void load_sg_static(void) {
    load_placement_pack(&weapon_pack, &weapon_mem, RESOURCE_ID_PREZR_SG_STATIC_PACK);
    set_image_and_center_bottom(layer_weapon, &weapon_pack.resources[PREZR_SG_STATIC_SHTGA0], weaponPos);
}
void load_sg_fire(size_t index) {
    switch (index) {
    case 0: load_placement_pack(&weapon_pack, &weapon_mem, RESOURCE_ID_PREZR_SG_FIRE1_PACK);
    case 1: load_placement_pack(&weapon_pack, &weapon_mem, RESOURCE_ID_PREZR_SG_FIRE2_PACK);
    case 2: load_placement_pack(&weapon_pack, &weapon_mem, RESOURCE_ID_PREZR_SG_FIRE3_PACK);
    default: APP_LOG(APP_LOG_LEVEL_ERROR, "");
    }
    set_image_and_center_bottom(layer_weapon, &weapon_pack.resources[0], weaponPos);
}

void load_respawn(void) {
    load_placement_pack_offset(&respawn_pack, &zombie_mem, respawn_mem_offset, RESOURCE_ID_PREZR_RESPAWN_PACK);
    set_image_and_center(layer_respawnoverlay, &respawn_pack.resources[0], respawnPos);
}

// Constructor
void doom_init(struct tm* init_time, uint8_t batteryPercent, bool isCharging, bool hasBluetooth) {
  // Load resources
  doom_initialise_ui();
  init_static_resources();
  init_dynamic_resources();
  
  // Fire event handlers and set initial state
  set_time_display(init_time);
  set_battery_status(batteryPercent, isCharging);
  set_bluetooth_status(hasBluetooth);

  // Set the face and walk animation
  doom_animate();
  
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void doom_destroy(void) {
  window_stack_remove(s_window, true);
}

void doom_animate(void) {
  if (batteryCharging) {
    int index = (batteryPercent >= 70)
      ? PREZR_FACEBATTERY_STFGOD0
      : (70 - batteryPercent) * 4 / 70;
    bitmap_layer_set_bitmap(face, prezr_facebattery.resources[index].bitmap);        
  } else {
    face_index = rand() % current_face_pack->numResources;
    bitmap_layer_set_bitmap(face, current_face_pack->resources[face_index].bitmap);  
  }
  
  //uint8_t bat = batteryPercent >= 100 ? 0 : batteryPercent;
  //bitmap_layer_set_bitmap(num2, prezr_numerals.resources[bat / 10].bitmap);  
  //bitmap_layer_set_bitmap(num3, prezr_numerals.resources[bat % 10].bitmap);  
  
  if (walking) {
    walk_frame ^= 1;
    set_image_and_center_bottom(player, &prezr_zombiewalk.resources[walk_frame], enemyPos);
  }
}

static const int fire_frame_delay = 200;
static const int die_frame_delay = 200;
static const int respawn_frame_delay = 200;
static const int respawn_pause = 5000;

void respawn_frame(size_t frameNum) {
  if (frameNum == PREZR_RESPAWN_COUNT - 1) {
    // end of animation - end respawn
    layer_set_hidden(bitmap_layer_get_layer(respawnoverlay), true);
    prezr_unload_respawn();

    // end of entire animation
    can_start_new_anim = true;
  } else {
    // continue the animation
    frameNum++;
    set_image_and_center(respawnoverlay, &prezr_respawn.resources[frameNum], respawnPos);
    
    app_timer_register(
      respawn_frame_delay, 
      (AppTimerCallback) respawn_frame,
      (void*) frameNum);     
  }
}

void respawn(void) {
  load_zombie_walk();
  walking = true;
  
  load_respawn();  
  
  // show respawn sprite
  layer_set_hidden(bitmap_layer_get_layer(respawnoverlay), false);
  
  app_timer_register(
    respawn_frame_delay, 
    (AppTimerCallback) respawn_frame,
    (void*) 0);   
}
    
void die_frame(size_t frameNum) {
  if (frameNum == PREZR_ZOMBIEDIE_COUNT - 1) {
    // end of animation - start respawn
    app_timer_register(
      respawn_pause, 
      (AppTimerCallback) respawn,
      NULL);     
  } else {
    // continue the animation
    frameNum++;
    set_image_and_center_bottom(player, &prezr_zombiedie.resources[frameNum], enemyPos);
    
    app_timer_register(
      die_frame_delay, 
      (AppTimerCallback) die_frame,
      (void*) frameNum);     
  }
}

void fire_frame2(size_t frameNum) {
  switch (frameNum) {
    case 0:
      prezr_unload_sg_fire1();
      prezr_load_sg_fire2();
      set_image_and_center_bottom(weapon, &prezr_sg_fire2.resources[0], weaponPos);
      break;
    case 1:
      prezr_unload_sg_fire2();
      prezr_load_sg_fire3();
      set_image_and_center_bottom(weapon, &prezr_sg_fire3.resources[0], weaponPos);
      break;
    case 2:      
      prezr_unload_sg_fire3();
      prezr_load_sg_static();
      set_image_and_center_bottom(weapon, &prezr_sg_static.resources[PREZR_SG_STATIC_SHTGA0], weaponPos);
      return; // end of animation
  }
    
  app_timer_register(
    fire_frame_delay, 
    (AppTimerCallback) fire_frame2,
    (void*) (frameNum+1));     
}

void fire_frame(void* unused) {
  // hide the muzzle-flash
  bitmap_layer_set_bitmap(muzzleflash, NULL);
  layer_set_hidden(bitmap_layer_get_layer(muzzleflash), true);
  
  prezr_unload_sg_static();
  prezr_load_sg_fire1();  
  set_image_and_center_bottom(weapon, &prezr_sg_fire1.resources[0], weaponPos);
  
  app_timer_register(
      fire_frame_delay, 
      (AppTimerCallback) fire_frame2,
      (void*) 0);
}

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
  } else {
    // single digit
    layer_set_hidden(bitmap_layer_get_layer(num0), true);
  }
  
  bitmap_layer_set_bitmap(num1, prezr_numerals.resources[hour % 10].bitmap);
  bitmap_layer_set_bitmap(num2, prezr_numerals.resources[t->tm_min / 10].bitmap);
  bitmap_layer_set_bitmap(num3, prezr_numerals.resources[t->tm_min % 10].bitmap);
}

void set_battery_status(uint8_t percent, bool charging) {
    // unload the current face-pack
    prezr_destroy(current_face_pack);

    batteryCharging = charging;
    batteryPercent = percent;

    // select a new face-pack
    if (charging) {
        current_face_pack = &prezr_facebattery;
        prezr_load_facebattery();
    }
    else if (percent < 15) {
        current_face_pack = &prezr_face4;
        prezr_load_face4();
    }
    else if (percent < 30) {
        current_face_pack = &prezr_face3;
        prezr_load_face3();
    }
    else if (percent < 50) {
        current_face_pack = &prezr_face2;
        prezr_load_face2();
    }
    else if (percent < 70) {
        current_face_pack = &prezr_face1;
        prezr_load_face1();
    }
    else {
        current_face_pack = &prezr_face0;
        prezr_load_face0();
    }
}

void set_bluetooth_status(bool hasBluetooth) {
  if (hasBluetooth) {
    prezr_load_lamp_on();
    bitmap_layer_set_bitmap(lamp, prezr_lamp_on.resources[0].bitmap);      
  } else {
    prezr_load_lamp_off();
    bitmap_layer_set_bitmap(lamp, prezr_lamp_off.resources[0].bitmap);      
  }
  bluetoothState = hasBluetooth;
}

void doom_play_animation(void) {
  if (can_start_new_anim) {
    // evict the walk animation and load the die animation
    load_zombiedie();
    walking = false;
    can_start_new_anim = false;
    
    // show muzzleflash
    layer_set_hidden(bitmap_layer_get_layer(muzzleflash), false);
    bitmap_layer_set_bitmap(muzzleflash, prezr_sg_static.resources[PREZR_SG_STATIC_SHTFA0].bitmap);
    
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

void doom_time_changed(struct tm *t) {
  set_time_display(t);
  doom_play_animation();
}

void doom_battery_level_changed(uint8_t percent, bool charging) {
  set_battery_status(percent, charging);  
  doom_animate();
}

void doom_bluetooth_changed(bool connected) {
  if (bluetoothState == connected) {
    return;
  }

  bluetoothState = connected;
  
  if (bluetoothState) {
    prezr_unload_lamp_off();
    prezr_load_lamp_on();
    bitmap_layer_set_bitmap(lamp, prezr_lamp_on.resources[0].bitmap);
  } else {
    prezr_unload_lamp_on();
    prezr_load_lamp_off();
    bitmap_layer_set_bitmap(lamp, prezr_lamp_off.resources[0].bitmap);
  }
}
