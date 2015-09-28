#pragma once

void start_zombie_walk(void);
void animate_zombie_walk_anim(void);
void end_zombie_walk_anim(void);

void start_zombie_die_anim(void);
void animate_zombie_die_anim(size_t frame);
void end_zombie_die_anim(void);
bool at_end_of_zombie_die_anim(size_t index);

void start_weapon_static_anim(void);
void show_muzzle_flash_anim(void);
void hide_muzzle_flash_anim(void);
void end_weapon_static_anim(void);

void start_weapon_fire_anim(void);
void animate_weapon_fire(size_t index);
void end_weapon_fire_anum(void);
bool at_end_of_weapon_fire_anim(size_t index);

void start_respawn_anim(void);
void animate_respawn(size_t frame);
void end_respawn_anim(void);
bool at_end_of_respawn_anim(size_t index);

void start_face_anim(uint8_t percent, bool charging);
void animate_face(uint8_t health, bool charging);

void set_lamp_anim(bool on);
