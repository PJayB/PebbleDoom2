#include <pebble.h>
#include "packhelpers.h"
#include "doom_res.h"
#include "doom_anim.h"
#include "doom_ui.h"

// Layout constants
static const GPoint enemyPos = {48 + 25, 18 + 56};
static const GPoint weaponPos = {69, 136};
static const GPoint respawnPos = {48 + 25, 18 + 28};


#define ALLOW_ASSERTS
#ifdef ALLOW_ASSERTS
#   define ASSERT(x) if((x)) {} else { APP_LOG(APP_LOG_LEVEL_DEBUG, "Assertion failed: '" #x "'"); }
#else
#   define ASSERT(x) (void)(x)
#endif


// Shorthand APIs for switching animations

//
// Zombie
//
bool in_zombie_walk = false;
bool in_zombie_die = false;
int walk_frame = 0;

void start_zombie_walk(void) {
    ASSERT(!in_zombie_die);
    load_placement_pack(&zombie_pack, &zombie_mem, RESOURCE_ID_PREZR_ZOMBIEWALK_PACK);
    set_image_and_center_bottom(layer_player, &zombie_pack.resources[0], zombiePos);
    in_zombie_walk = true;
}

void animate_zombie_walk_anim(void) {
    ASSERT(in_zombie_walk);

    walk_frame ^= 1;
    set_image_and_center_bottom(layer_player, &zombie_pack.resources[walk_frame], zombiePos);
}

void end_zombie_walk_anim(void) {
    ASSERT(in_zombie_walk);
    in_zombie_walk = false;
}

void start_zombie_die_anim(void) {
    ASSERT(!in_zombie_die);

    load_placement_pack(&zombie_pack, &zombie_mem, RESOURCE_ID_PREZR_ZOMBIEDIE_PACK);
    set_image_and_center_bottom(layer_player, &zombie_pack.resources[0], zombiePos);
}

void animate_zombie_die_anim(size_t frame) {
    ASSERT(in_zombie_die);
    set_image_and_center_bottom(layer_player, &zombie_pack.resources[frame], zombiePos);
}

void end_zombie_die_anim(void) {
    ASSERT(in_zombie_die);
    in_zombie_die = false;
}

bool at_end_of_zombie_die_anim(size_t index) {
    return index >= (zombie_pack.numResources - 1);
}

// 
// Weapon fire animation
//
bool in_weapon_static = false;
bool in_weapon_fire = false;

void start_weapon_static_anim(void) {
    ASSERT(!in_weapon_static);
    load_placement_pack(&weapon_pack, &weapon_mem, RESOURCE_ID_PREZR_SG_STATIC_PACK);
    set_image_and_center_bottom(layer_weapon, &weapon_pack.resources[PREZR_SG_STATIC_SHTGA0], weaponPos);
    in_weapon_static = true;
}

void show_muzzle_flash_anim(void) {
    ASSERT(in_weapon_static);
    set_image_and_center_bottom(layer_muzzleflash, &weapon_pack.resources[PREZR_SG_STATIC_SHTFA0], weaponPos);
    layer_set_hidden(bitmap_layer_get_layer(layer_muzzleflash), false);
}

void hide_muzzle_flash_anim(void) {
    ASSERT(in_weapon_static);
    layer_set_hidden(bitmap_layer_get_layer(layer_muzzleflash), true);
}

void end_weapon_static_anim(void) {
    ASSERT(in_weapon_static);
    in_weapon_static = false;
}

uint32_t get_weapon_fire_anim_resource(size_t index) {
    switch (index) {
    case 0: return RESOURCE_ID_PREZR_SG_FIRE1_PACK;
    case 1: return RESOURCE_ID_PREZR_SG_FIRE2_PACK;
    case 2: return RESOURCE_ID_PREZR_SG_FIRE3_PACK;
    default: return 0;
    }
}

bool at_end_of_weapon_fire_anim(size_t index) {
    return get_weapon_fire_anim_resource(index+1) != 0;
}

void start_weapon_fire_anim(void) {
    ASSERT(!in_weapon_fire);
    animate_weapon_fire(0);
    in_weapon_fire = true;
}

void animate_weapon_fire(size_t index) {
    ASSERT(in_weapon_fire);
    uint32_t res = get_weapon_fire_anim_resource(index);
    if (res != 0) {
        load_placement_pack(&weapon_pack, &weapon_mem, res);
        set_image_and_center_bottom(layer_weapon, &weapon_pack.resources[0], weaponPos);
    }
}

void end_weapon_fire_anum(void) {
    ASSERT(in_weapon_fire);
    in_weapon_fire = false;
}

//
// Respawn animation
//
bool in_respawn = false;

void start_respawn_anim(void) {
    ASSERT(!in_respawn);
    load_respawn_pack();
    set_image_and_center(layer_respawnoverlay, &respawn_pack.resources[0], respawnPos);
    layer_set_hidden(bitmap_layer_get_layer(layer_respawnoverlay), false);
    in_respawn = true;
}

void animate_respawn(size_t frame) {
    ASSERT(in_respawn);
    if (frame < respawn_pack.numResources) {
        set_image_and_center(layer_respawnoverlay, &respawn_pack.resources[frame], respawnPos);
    }
}

void end_respawn_anim(void) {
    ASSERT(in_respawn);
    unload_respawn_pack();
    layer_set_hidden(bitmap_layer_get_layer(layer_respawnoverlay), true);
    in_respawn = false;
}

bool at_end_of_respawn_anim(size_t index) {
    return index >= (respawn_pack.numResources - 1);
}

//
// Face animation
//
bool in_charging = false;

void start_face_anim(uint8_t percent, bool charging) {
    in_charging = charging;

    if (charging) {
        change_face_pack(face_type_charging);
    }
    else if (percent < 15) {
        change_face_pack(face_type_lowest);
    }
    else if (percent < 30) {
        change_face_pack(face_type_low);
    }
    else if (percent < 50) {
        change_face_pack(face_type_med);
    }
    else if (percent < 70) {
        change_face_pack(face_type_high);
    }
    else {
        change_face_pack(face_type_highest);
    }

    animate_face(percent, charging);
}

void animate_face(uint8_t health, bool charging) {
    if (charging) {
        ASSERT(in_charging);
        int index = (health >= 70)
            ? PREZR_FACEBATTERY_STFGOD0
            : (70 - health) * 4 / 70;
        bitmap_layer_set_bitmap(layer_face, face_pack.resources[index].bitmap);
    }
    else {
        ASSERT(!in_charging);
        uint32_t face_index = rand() % face_pack.numResources;
        bitmap_layer_set_bitmap(layer_face, face_pack.resources[face_index].bitmap);
    }
}

//
// Lamp animation
//
void set_lamp_anim(bool on) {
    change_bluetooth_pack(hasBluetooth);
    bitmap_layer_set_bitmap(layer_lamp, lamp_pack.resources[0].bitmap);
}
