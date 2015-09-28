#pragma once

extern Window *s_window;
extern BitmapLayer *layer_statusbar_bg;
extern BitmapLayer *layer_level_bg;
extern BitmapLayer *layer_player;
extern BitmapLayer *layer_lamp;
extern BitmapLayer *layer_num0;
extern BitmapLayer *layer_num1;
extern BitmapLayer *layer_num2;
extern BitmapLayer *layer_num3;
extern BitmapLayer *layer_weapon;
extern BitmapLayer *layer_muzzleflash;
extern BitmapLayer *layer_face;
extern BitmapLayer *layer_respawnoverlay;

void doom_initialise_ui(void);
void doom_destroy_ui(void);
