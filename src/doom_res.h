#pragma once

// Static packs
extern prezr_pack_t background_pack;
extern prezr_pack_t numeric_pack;

// Infrequently changing packs
extern prezr_pack_t lamp_pack;
extern prezr_pack_t face_pack;

// Dynamic packs (frequently changing)
extern prezr_pack_t weapon_pack;
extern prezr_pack_t zombie_pack;
extern prezr_pack_t respawn_pack;

void load_resources(void);
void unload_resources(void);

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

