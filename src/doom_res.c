#include <pebble.h>
#include "prezr.h"
#include "prezrpackages.h"
#include "packhelpers.h"
#include "doom_res.h"

#define countof(x) (sizeof(x)/sizeof(x[0]))

// Placement memory for animating/frequently changing sprites
placement_block_t weapon_mem = {NULL};
placement_block_t zombie_mem = {NULL};
placement_block_t face_mem = {NULL};
placement_block_t lamp_mem = {NULL};

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

size_t get_respawn_mem_offset() {
    return respawn_mem_offset;
}

// Initialize the resources that never change
void init_static_resources(void) {
    load_pack(&background_pack, RESOURCE_ID_PREZR_BACKGROUND_PACK);
    load_pack(&numeric_pack, RESOURCE_ID_PREZR_NUMERALS_PACK);
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
        get_resource_size(RESOURCE_ID_PREZR_SG_STATIC_PACK),
        get_resource_size(RESOURCE_ID_PREZR_SG_FIRE1_PACK),
        get_resource_size(RESOURCE_ID_PREZR_SG_FIRE2_PACK),
        get_resource_size(RESOURCE_ID_PREZR_SG_FIRE3_PACK)
    };

    size_t face_resource_sizes[] = {
        get_resource_size(RESOURCE_ID_PREZR_FACEBATTERY_PACK),
        get_resource_size(RESOURCE_ID_PREZR_FACE4_PACK),
        get_resource_size(RESOURCE_ID_PREZR_FACE3_PACK),
        get_resource_size(RESOURCE_ID_PREZR_FACE2_PACK),
        get_resource_size(RESOURCE_ID_PREZR_FACE1_PACK),
        get_resource_size(RESOURCE_ID_PREZR_FACE0_PACK)
    };

    size_t lamp_resource_sizes[] = {
        get_resource_size(RESOURCE_ID_PREZR_LAMP_ON_PACK),
        get_resource_size(RESOURCE_ID_PREZR_LAMP_OFF_PACK)
    };

    // Allocate the memory for the animations
    init_shared_placement_block(&zombie_mem, zombie_resource_sizes, countof(zombie_resource_sizes));
    init_shared_placement_block(&weapon_mem, weapon_resource_sizes, countof(weapon_resource_sizes));
    init_shared_placement_block(&face_mem, face_resource_sizes, countof(face_resource_sizes));
    init_shared_placement_block(&lamp_mem, lamp_resource_sizes, countof(lamp_resource_sizes));
}

void destroy_dynamic_resources(void) {
    // Infrequently changing packs
    unload_pack_placement(&lamp_pack);
    unload_pack_placement(&face_pack);

    // Frequently changing
    unload_pack_placement(&respawn_pack);
    unload_pack_placement(&weapon_pack);
    unload_pack_placement(&zombie_pack);

    // Placement buffers
    destroy_shared_placement_block(&weapon_mem);
    destroy_shared_placement_block(&zombie_mem);
    destroy_shared_placement_block(&lamp_mem);
    destroy_shared_placement_block(&face_mem);
}

//
// Init/shutdown API
//

void load_resources(void) {
    init_static_resources();
    init_dynamic_resources();
}

void unload_resources(void) {
    destroy_static_resources();
    destroy_dynamic_resources();
}

//
// Respawn pack
//
void load_respawn_pack(void) {
    load_pack_placement_offset(&respawn_pack, &zombie_mem, respawn_mem_offset, RESOURCE_ID_PREZR_RESPAWN_PACK);
}
void unload_respawn_pack(void) {
    unload_pack_placement(&respawn_pack);
}

//
// Zombie pack
//
void load_zombie_walk_pack(void) {
    load_pack_placement(&zombie_pack, &zombie_mem, RESOURCE_ID_PREZR_ZOMBIEWALK_PACK);
}
void load_zombie_die_pack(void) {
    load_pack_placement(&zombie_pack, &zombie_mem, RESOURCE_ID_PREZR_ZOMBIEDIE_PACK);
}

//
// Weapon pack
//
uint32_t get_weapon_fire_anim_resource(size_t index) {
    switch (index) {
    case 0: return RESOURCE_ID_PREZR_SG_FIRE1_PACK;
    case 1: return RESOURCE_ID_PREZR_SG_FIRE2_PACK;
    case 2: return RESOURCE_ID_PREZR_SG_FIRE3_PACK;
    default: return 0;
    }
}

void load_weapon_static_pack(void) {
    load_pack_placement(&weapon_pack, &weapon_mem, RESOURCE_ID_PREZR_SG_STATIC_PACK);
}
void load_weapon_fire_pack(uint32_t index) {
    uint32_t res = get_weapon_fire_anim_resource(index);
    load_pack_placement(&weapon_pack, &weapon_mem, res);
}

//
// Face pack
//
static const uint32_t face_type_map[] = {
    RESOURCE_ID_PREZR_FACEBATTERY_PACK,
    RESOURCE_ID_PREZR_FACE4_PACK,
    RESOURCE_ID_PREZR_FACE3_PACK,
    RESOURCE_ID_PREZR_FACE2_PACK,
    RESOURCE_ID_PREZR_FACE1_PACK,
    RESOURCE_ID_PREZR_FACE0_PACK
};

void change_face_pack(face_type_t type) {
    load_pack_placement(&face_pack, &face_mem, face_type_map[type]);
}

void change_bluetooth_pack(bool on) {
    uint32_t res = on ? RESOURCE_ID_PREZR_LAMP_ON_PACK : RESOURCE_ID_PREZR_LAMP_OFF_PACK;
    load_pack_placement(&lamp_pack, &lamp_mem, res);
}

// 
// Access resources 
//
const GBitmap* get_background_resource(void) { return background_pack.resources[PREZR_BACKGROUND_BACKGROUND].bitmap; }
const GBitmap* get_statusbar_resource(void) { return background_pack.resources[PREZR_BACKGROUND_STATUSBAR].bitmap; }
const GBitmap* get_lamp_resource(void) { return lamp_pack.resources[0].bitmap; }
const GBitmap* get_face_resource(uint32_t id) { return face_pack.resources[id].bitmap; }
const GBitmap* get_numeral_resource(uint32_t id) { return numeric_pack.resources[id].bitmap; }

const GBitmap* get_random_face_resource(void) { return face_pack.resources[rand() % face_pack.numResources].bitmap; }
