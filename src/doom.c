#include <pebble.h>
#include "doom.h"
#include "prezr.h"
  
#define PREZR_IMPORT_PLAYERWALK_PACK
#define PREZR_IMPORT_PLAYERDIE_PACK
#define PREZR_IMPORT_NUMERALS_PACK
#define PREZR_IMPORT_WEAPONSTATIC_PACK
#define PREZR_IMPORT_WEAPONFIRE1_PACK
#define PREZR_IMPORT_WEAPONFIRE2_PACK
#define PREZR_IMPORT_WEAPONFIRE3_PACK
#define PREZR_IMPORT_RESPAWN_PACK
#define PREZR_IMPORT_LAMP_ON_PACK
#define PREZR_IMPORT_LAMP_OFF_PACK
#define PREZR_IMPORT_BACKGROUND_PACK
#define PREZR_IMPORT_FACE0_PACK
#define PREZR_IMPORT_FACE1_PACK
#define PREZR_IMPORT_FACE2_PACK
#define PREZR_IMPORT_FACE3_PACK
#define PREZR_IMPORT_FACE4_PACK
#define PREZR_IMPORT_FACEBATTERY_PACK
#include "prezrpackages.h"
  
static GPoint enemyPos = { 48+25, 18+56 };
static GPoint weaponPos = { 69, 136 };
static GPoint respawnPos = { 48+25, 18+28 };
static const int numeric_height = 138;
static const int weapon_fire_frames = 3;

int face_index = 0;
prezr_pack_t* current_face_pack = &prezr_face0;
uint8_t batteryPercent = 100;
bool batteryCharging = false;
bool bluetoothState = false;
bool walking = true;
int walk_frame = 0;

void image_center(Layer* layer, GPoint location, GSize size) {
  int16_t x = location.x - size.w / 2;
  int16_t y = location.y - size.h / 2;
  
  GRect rect = {
    { x, y, },
    size
  };
  
  layer_set_frame(layer, rect);
}

void image_center_bottom(Layer* layer, GPoint location, GSize size) {
  int16_t x = location.x - size.w / 2;
  int16_t y = location.y - size.h;
  
  GRect rect = {
    { x, y, },
    size
  };
  
  layer_set_frame(layer, rect);
}

void set_image_and_center(BitmapLayer* layer, const prezr_bitmap_t* resource, GPoint location) {
  bitmap_layer_set_bitmap(layer, resource->bitmap);
  image_center(bitmap_layer_get_layer(layer), location, GSize(resource->width, resource->height));
}

void set_image_and_center_bottom(BitmapLayer* layer, const prezr_bitmap_t* resource, GPoint location) {
  bitmap_layer_set_bitmap(layer, resource->bitmap);
  image_center_bottom(bitmap_layer_get_layer(layer), location, GSize(resource->width, resource->height));
}
  
// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static BitmapLayer *statusbar_bg;
static BitmapLayer *level_bg;
static BitmapLayer *player;
static BitmapLayer *lamp;
static BitmapLayer *num0;
static BitmapLayer *num1;
static BitmapLayer *num2;
static BitmapLayer *num3;
static BitmapLayer *weapon;
static BitmapLayer *muzzleflash;
static BitmapLayer *face;
static BitmapLayer *respawnoverlay;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
      
  // statusbar_bg
  statusbar_bg = bitmap_layer_create(GRect(0, 136, 144, 32));
  bitmap_layer_set_background_color(statusbar_bg, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)statusbar_bg);
  
  // level_bg
  level_bg = bitmap_layer_create(GRect(0, 0, 144, 136));
  bitmap_layer_set_background_color(level_bg, GColorWhite);
  layer_add_child(window_get_root_layer(s_window), (Layer *)level_bg);
  
  // player
  player = bitmap_layer_create(GRect(48, 18, 50, 56));
  bitmap_layer_set_background_color(player, GColorClear);
  bitmap_layer_set_compositing_mode(player, GCompOpSet);
  layer_add_child(window_get_root_layer(s_window), (Layer *)player);
  
  // respawn
  respawnoverlay = bitmap_layer_create(GRect(48, 18, 50, 56));
  bitmap_layer_set_background_color(respawnoverlay, GColorClear);
  bitmap_layer_set_compositing_mode(respawnoverlay, GCompOpSet);
  layer_set_hidden(bitmap_layer_get_layer(respawnoverlay), true);
  layer_add_child(window_get_root_layer(s_window), (Layer *)respawnoverlay);
  
  // lamp
  lamp = bitmap_layer_create(GRect(110, 27, 21, 60));
  bitmap_layer_set_background_color(lamp, GColorClear);
  bitmap_layer_set_compositing_mode(lamp, GCompOpSet);
  layer_add_child(window_get_root_layer(s_window), (Layer *)lamp);
  
  // weapon
  weapon = bitmap_layer_create(GRect(30, 76, 79, 60));
  bitmap_layer_set_background_color(weapon, GColorClear);
  bitmap_layer_set_compositing_mode(weapon, GCompOpSet);
  layer_add_child(window_get_root_layer(s_window), (Layer *)weapon);
  
  // muzzleflash
  muzzleflash = bitmap_layer_create(GRect(50, 63, 44, 31));
  bitmap_layer_set_background_color(muzzleflash, GColorClear);
  bitmap_layer_set_compositing_mode(muzzleflash, GCompOpSet);
  layer_set_hidden(bitmap_layer_get_layer(muzzleflash), true);
  layer_add_child(window_get_root_layer(s_window), (Layer *)muzzleflash);
  
  // num0
  num0 = bitmap_layer_create(GRect(13, numeric_height, 14, 16));
  bitmap_layer_set_background_color(num0, GColorClear);
  bitmap_layer_set_compositing_mode(num0, GCompOpSet);
  layer_add_child(window_get_root_layer(s_window), (Layer *)num0);
  
  // num1
  num1 = bitmap_layer_create(GRect(27, numeric_height, 14, 16));
  bitmap_layer_set_background_color(num1, GColorClear);
  bitmap_layer_set_compositing_mode(num1, GCompOpSet);
  layer_add_child(window_get_root_layer(s_window), (Layer *)num1);
  
  // num2
  num2 = bitmap_layer_create(GRect(102, numeric_height, 14, 16));
  bitmap_layer_set_background_color(num2, GColorClear);
  bitmap_layer_set_compositing_mode(num2, GCompOpSet);
  layer_add_child(window_get_root_layer(s_window), (Layer *)num2);
  
  // num3
  num3 = bitmap_layer_create(GRect(116, numeric_height, 14, 16));
  bitmap_layer_set_background_color(num3, GColorClear);
  bitmap_layer_set_compositing_mode(num3, GCompOpSet);
  layer_add_child(window_get_root_layer(s_window), (Layer *)num3);
  
  // face
  face = bitmap_layer_create(GRect(58, numeric_height - 1, 29, 30));
  bitmap_layer_set_background_color(face, GColorClear);
  bitmap_layer_set_compositing_mode(face, GCompOpSet);
  layer_add_child(window_get_root_layer(s_window), (Layer *)face);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(statusbar_bg);
  bitmap_layer_destroy(level_bg);
  bitmap_layer_destroy(player);
  bitmap_layer_destroy(lamp);
  bitmap_layer_destroy(weapon);
  bitmap_layer_destroy(num0);
  bitmap_layer_destroy(num1);
  bitmap_layer_destroy(num2);
  bitmap_layer_destroy(num3);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
  
  // delete images
  prezr_unload_background();
  prezr_unload_playerwalk();
  prezr_unload_lamp_on();
  prezr_unload_weaponstatic();
  prezr_unload_numerals();
  prezr_unload_face0();
  
  // delete animations
  //animSpriteDef_destroy(&animDef_doom_guy_walk);
  //animSpriteDef_destroy(&animDef_doom_guy_firing);
}

void doom_init(struct tm* init_time, uint8_t batteryPercent, bool isCharging, bool hasBluetooth) {
  initialise_ui();
  
  // load images
  prezr_load_background();
  bitmap_layer_set_bitmap(level_bg, prezr_background.resources[PREZR_BACKGROUND_BACKGROUND].bitmap);
  bitmap_layer_set_bitmap(statusbar_bg, prezr_background.resources[PREZR_BACKGROUND_STATUSBAR].bitmap);
  prezr_load_numerals();
  prezr_load_face0();
  bitmap_layer_set_bitmap(face, prezr_face0.resources[0].bitmap);
    
  prezr_load_weaponstatic();
  set_image_and_center_bottom(weapon, &prezr_weaponstatic.resources[PREZR_WEAPONSTATIC_SHTGA0], weaponPos);
  
  prezr_load_playerwalk();
  set_image_and_center_bottom(player, &prezr_playerwalk.resources[0], enemyPos);
  
  // Fire event handlers and set initial state
  doom_time_changed(init_time);
  doom_battery_level_changed(batteryPercent, isCharging);
  if (hasBluetooth) {
    prezr_load_lamp_on();
    bitmap_layer_set_bitmap(lamp, prezr_lamp_on.resources[0].bitmap);      
  } else {
    prezr_load_lamp_off();
    bitmap_layer_set_bitmap(lamp, prezr_lamp_off.resources[0].bitmap);      
  }
  bluetoothState = hasBluetooth;
  
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
    set_image_and_center_bottom(player, &prezr_playerwalk.resources[walk_frame], enemyPos);
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
  prezr_unload_playerdie();
  prezr_load_playerwalk();
  set_image_and_center_bottom(player, &prezr_playerwalk.resources[walk_frame], enemyPos);
  walking = true;
  
  prezr_load_respawn();  
  
  // show respawn sprite
  layer_set_hidden(bitmap_layer_get_layer(respawnoverlay), false);
  set_image_and_center(respawnoverlay, &prezr_respawn.resources[0], respawnPos);
  
  app_timer_register(
    respawn_frame_delay, 
    (AppTimerCallback) respawn_frame,
    (void*) 0);   
}
    
void die_frame(size_t frameNum) {
  if (frameNum == PREZR_PLAYERDIE_COUNT - 1) {
    // end of animation - start respawn
    app_timer_register(
      respawn_pause, 
      (AppTimerCallback) respawn,
      NULL);     
  } else {
    // continue the animation
    frameNum++;
    set_image_and_center_bottom(player, &prezr_playerdie.resources[frameNum], enemyPos);
    
    app_timer_register(
      die_frame_delay, 
      (AppTimerCallback) die_frame,
      (void*) frameNum);     
  }
}

void fire_frame2(size_t frameNum) {
  switch (frameNum) {
    case 0:
      prezr_unload_weaponfire1();
      prezr_load_weaponfire2();
      set_image_and_center_bottom(weapon, &prezr_weaponfire2.resources[0], weaponPos);
      break;
    case 1:
      prezr_unload_weaponfire2();
      prezr_load_weaponfire3();
      set_image_and_center_bottom(weapon, &prezr_weaponfire3.resources[0], weaponPos);
      break;
    case 2:      
      prezr_unload_weaponfire2();
      prezr_load_weaponstatic();
      set_image_and_center_bottom(weapon, &prezr_weaponstatic.resources[PREZR_WEAPONSTATIC_SHTGA0], weaponPos);
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
  
  prezr_unload_weaponstatic();
  prezr_load_weaponfire1();  
  set_image_and_center_bottom(weapon, &prezr_weaponfire1.resources[0], weaponPos);
  
  app_timer_register(
      fire_frame_delay, 
      (AppTimerCallback) fire_frame2,
      (void*) 0);
}

void doom_time_changed(struct tm *t) {
  if (clock_is_24h_style() || t->tm_hour > 9) {
    // two numbers here
    layer_set_hidden(bitmap_layer_get_layer(num0), false);
    bitmap_layer_set_bitmap(num0, prezr_numerals.resources[t->tm_hour / 10].bitmap);
  } else {
    // single digit
    layer_set_hidden(bitmap_layer_get_layer(num0), true);
  }
  
  bitmap_layer_set_bitmap(num1, prezr_numerals.resources[t->tm_hour % 10].bitmap);
  bitmap_layer_set_bitmap(num2, prezr_numerals.resources[t->tm_min / 10].bitmap);
  bitmap_layer_set_bitmap(num3, prezr_numerals.resources[t->tm_min % 10].bitmap);
  
  if (walking) {
    // evict the walk animation and load the die animation
    prezr_unload_playerwalk();
    prezr_load_playerdie();
    set_image_and_center_bottom(player, &prezr_playerdie.resources[0], enemyPos);
    walking = false;
    
    // show muzzleflash
    layer_set_hidden(bitmap_layer_get_layer(muzzleflash), false);
    bitmap_layer_set_bitmap(muzzleflash, prezr_weaponstatic.resources[PREZR_WEAPONSTATIC_SHTFA0].bitmap);
    
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

void doom_battery_level_changed(uint8_t percent, bool charging) {
  // unload the current face-pack
  prezr_destroy(current_face_pack);
  
  batteryCharging = charging;
  batteryPercent = percent;
  
  // select a new face-pack
  if (charging) {
    current_face_pack = &prezr_facebattery;
    prezr_load_facebattery();
  } else if (percent < 15) {
    current_face_pack = &prezr_face4;
    prezr_load_face4();
  } else if (percent < 30) {
    current_face_pack = &prezr_face3;
    prezr_load_face3();
  } else if (percent < 50) {
    current_face_pack = &prezr_face2;
    prezr_load_face2();
  } else if (percent < 70) {
    current_face_pack = &prezr_face1;
    prezr_load_face1();  
  } else {
    current_face_pack = &prezr_face0;
    prezr_load_face0();  
  }
  
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
