#include <pebble.h>
#include "doom_ui.h"

static const int numeric_height = 138;

Window *s_window;
BitmapLayer *layer_statusbar_bg;
BitmapLayer *layer_level_bg;
BitmapLayer *layer_player;
BitmapLayer *layer_lamp;
BitmapLayer *layer_num0;
BitmapLayer *layer_num1;
BitmapLayer *layer_num2;
BitmapLayer *layer_num3;
BitmapLayer *layer_weapon;
BitmapLayer *layer_muzzleflash;
BitmapLayer *layer_face;
BitmapLayer *layer_respawnoverlay;

void doom_initialise_ui(void) {
    s_window = window_create();
#ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
#endif

    // statusbar_bg
    layer_statusbar_bg = bitmap_layer_create(GRect(0, 136, 144, 32));
    bitmap_layer_set_background_color(layer_statusbar_bg, GColorBlack);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_statusbar_bg);

    // level_bg
    layer_level_bg = bitmap_layer_create(GRect(0, 0, 144, 136));
    bitmap_layer_set_background_color(layer_level_bg, GColorWhite);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_level_bg);

    // player
    layer_player = bitmap_layer_create(GRect(48, 18, 50, 56));
    bitmap_layer_set_background_color(layer_player, GColorClear);
    bitmap_layer_set_compositing_mode(layer_player, GCompOpSet);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_player);

    // respawn
    layer_respawnoverlay = bitmap_layer_create(GRect(48, 18, 50, 56));
    bitmap_layer_set_background_color(layer_respawnoverlay, GColorClear);
    bitmap_layer_set_compositing_mode(layer_respawnoverlay, GCompOpSet);
    layer_set_hidden(bitmap_layer_get_layer(layer_respawnoverlay), true);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_respawnoverlay);

    // lamp
    layer_lamp = bitmap_layer_create(GRect(110, 27, 21, 60));
    bitmap_layer_set_background_color(layer_lamp, GColorClear);
    bitmap_layer_set_compositing_mode(layer_lamp, GCompOpSet);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_lamp);

    // weapon
    layer_weapon = bitmap_layer_create(GRect(30, 76, 79, 60));
    bitmap_layer_set_background_color(layer_weapon, GColorClear);
    bitmap_layer_set_compositing_mode(layer_weapon, GCompOpSet);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_weapon);

    // muzzleflash
    layer_muzzleflash = bitmap_layer_create(GRect(50, 63, 44, 31));
    bitmap_layer_set_background_color(layer_muzzleflash, GColorClear);
    bitmap_layer_set_compositing_mode(layer_muzzleflash, GCompOpSet);
    layer_set_hidden(bitmap_layer_get_layer(layer_muzzleflash), true);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_muzzleflash);

    // num0
    layer_num0 = bitmap_layer_create(GRect(13, numeric_height, 14, 16));
    bitmap_layer_set_background_color(layer_num0, GColorClear);
    bitmap_layer_set_compositing_mode(layer_num0, GCompOpSet);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_num0);

    // num1
    layer_num1 = bitmap_layer_create(GRect(27, numeric_height, 14, 16));
    bitmap_layer_set_background_color(layer_num1, GColorClear);
    bitmap_layer_set_compositing_mode(layer_num1, GCompOpSet);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_num1);

    // num2
    layer_num2 = bitmap_layer_create(GRect(102, numeric_height, 14, 16));
    bitmap_layer_set_background_color(layer_num2, GColorClear);
    bitmap_layer_set_compositing_mode(layer_num2, GCompOpSet);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_num2);

    // num3
    layer_num3 = bitmap_layer_create(GRect(116, numeric_height, 14, 16));
    bitmap_layer_set_background_color(layer_num3, GColorClear);
    bitmap_layer_set_compositing_mode(layer_num3, GCompOpSet);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_num3);

    // face
    layer_face = bitmap_layer_create(GRect(58, numeric_height - 1, 29, 30));
    bitmap_layer_set_background_color(layer_face, GColorClear);
    bitmap_layer_set_compositing_mode(layer_face, GCompOpSet);
    layer_add_child(window_get_root_layer(s_window), (Layer *) layer_face);
}

void doom_destroy_ui(void) {
    window_destroy(s_window);
    bitmap_layer_destroy(layer_statusbar_bg);
    bitmap_layer_destroy(layer_level_bg);
    bitmap_layer_destroy(layer_player);
    bitmap_layer_destroy(layer_lamp);
    bitmap_layer_destroy(layer_weapon);
    bitmap_layer_destroy(layer_num0);
    bitmap_layer_destroy(layer_num1);
    bitmap_layer_destroy(layer_num2);
    bitmap_layer_destroy(layer_num3);
    bitmap_layer_destroy(layer_face);
    bitmap_layer_destroy(layer_respawnoverlay);
}
