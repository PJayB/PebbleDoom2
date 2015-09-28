#include <pebble.h>
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

    size_t face_resource_sizes[] = {
        get_resource_size(RESOURCE_ID_PREZR_FACEBATTERY_PACK),
        get_resource_size(RESOURCE_ID_PREZR_FACE4_PACK),
        get_resource_size(RESOURCE_ID_PREZR_FACE3_PACK),
        get_resource_size(RESOURCE_ID_PREZR_FACE2_PACK),
        get_resource_size(RESOURCE_ID_PREZR_FACE1_PACK),
        get_resource_size(RESOURCE_ID_PREZR_FACE0_PACK)
    };

    size_t lamp_resource_sizes[] = {
        get_resource_size(RESOURCE_ID_SG_LAMP_ON_PACK),
        get_resource_size(RESOURCE_ID_SG_LAMP_OFF_PACK)
    };

    // Allocate the memory for the animations
    init_shared_placement_block(&zombie_mem, zombie_resource_sizes, countof(zombie_resource_sizes));
    init_shared_placement_block(&weapon_mem, weapon_resource_sizes, countof(weapon_resource_sizes));
    init_shared_placement_block(&face_mem, face_resource_sizes, countof(face_resource_sizes));
    init_shared_placement_block(&lamp_mem, lamp_resource_sizes, countof(lamp_resource_sizes));
}

void destroy_dynamic_resources(void) {
    // Infrequently changing packs
    prezr_placement_destroy(&lamp_pack);
    prezr_placement_destroy(&face_pack);

    // Frequently changing
    prezr_placement_destroy(&respawn_pack);
    prezr_placement_destroy(&weapon_pack);
    prezr_placement_destroy(&zombie_pack);

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
    load_placement_pack_offset(&respawn_pack, &zombie_mem, respawn_mem_offset, RESOURCE_ID_PREZR_RESPAWN_PACK);
}
void unload_respawn_pack(void) {
    unload_placement_pack(&respawn_pack);
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
    load_placement_pack(&face_pack, &face_mem, face_type_map[type]);
}

void change_bluetooth_pack(bool on) {
    uint32_t res = on ? RESOURCE_ID_PREZR_LAMP_ON_PACK : RESOURCE_ID_PREZR_LAMP_OFF_PACK;
    load_placement_pack(&lamp_pack, &lamp_mem, res);
}
