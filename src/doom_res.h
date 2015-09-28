#pragma once

//
// Initializes/destroys all resources
//
void load_resources(void);
void unload_resources(void);

//
// Switch out resources
//
void load_zombie_walk_pack(void);
void load_zombie_die_pack(void);

uint32_t get_weapon_fire_anim_resource(size_t index);
void load_weapon_static_pack(void);
void load_weapon_fire_pack(uint32_t index);

void load_respawn_pack(void);
void unload_respawn_pack(void);

typedef enum face_type_e {
    face_type_charging,
    face_type_lowest,
    face_type_low,
    face_type_med,
    face_type_high,
    face_type_highest
} face_type_t;

void change_face_pack(face_type_t type);
void change_bluetooth_pack(bool on);

// 
// Access resources 
//
const GBitmap* get_background_resource(void);
const GBitmap* get_statusbar_resource(void);
const GBitmap* get_lamp_resource(void);
const GBitmap* get_numeral_resource(uint32_t num);
const GBitmap* get_face_resource(uint32_t index);
const GBitmap* get_random_face_resource(void);

// Dynamic packs (frequently changing so directly exposed)
extern prezr_pack_t weapon_pack;
extern prezr_pack_t zombie_pack;
extern prezr_pack_t respawn_pack;


