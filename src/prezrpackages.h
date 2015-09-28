#pragma once

// ------------------------- background -------------------------
#define PREZR_BACKGROUND_CHECKSUM 0x96DB257D

typedef enum prezr_pack_background_e {
  PREZR_BACKGROUND_BACKGROUND, // 144x136 Bit8
  PREZR_BACKGROUND_STATUSBAR, // 144x32 Bit2Palettized
  PREZR_BACKGROUND_COUNT
} prezr_pack_background_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_BACKGROUND_PACK)
prezr_pack_t prezr_background;
void prezr_load_background() {
  int r = prezr_init(&prezr_background, RESOURCE_ID_PREZR_BACKGROUND_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'background' failed with code %d", r);
  if (prezr_background.numResources != PREZR_BACKGROUND_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'background' resource count mismatch");
}
void prezr_unload_background() {
  prezr_destroy(&prezr_background);
}
#else
extern prezr_pack_t prezr_background;
extern void prezr_load_background();
extern void prezr_unload_background();
#endif // PREZR_IMPORT

// ------------------------- face0 -------------------------
#define PREZR_FACE0_CHECKSUM 0x96DC0F62

typedef enum prezr_pack_face0_e {
  PREZR_FACE0_STFST00, // 24x29 Bit4Palettized
  PREZR_FACE0_STFST01, // 24x29 Bit4Palettized
  PREZR_FACE0_STFST02, // 24x29 Bit4Palettized
  PREZR_FACE0_COUNT
} prezr_pack_face0_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_FACE0_PACK)
prezr_pack_t prezr_face0;
void prezr_load_face0() {
  int r = prezr_init(&prezr_face0, RESOURCE_ID_PREZR_FACE0_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'face0' failed with code %d", r);
  if (prezr_face0.numResources != PREZR_FACE0_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'face0' resource count mismatch");
}
void prezr_unload_face0() {
  prezr_destroy(&prezr_face0);
}
#else
extern prezr_pack_t prezr_face0;
extern void prezr_load_face0();
extern void prezr_unload_face0();
#endif // PREZR_IMPORT

// ------------------------- face1 -------------------------
#define PREZR_FACE1_CHECKSUM 0x96DC8497

typedef enum prezr_pack_face1_e {
  PREZR_FACE1_STFST10, // 24x29 Bit4Palettized
  PREZR_FACE1_STFST11, // 24x29 Bit8
  PREZR_FACE1_STFST12, // 24x29 Bit4Palettized
  PREZR_FACE1_COUNT
} prezr_pack_face1_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_FACE1_PACK)
prezr_pack_t prezr_face1;
void prezr_load_face1() {
  int r = prezr_init(&prezr_face1, RESOURCE_ID_PREZR_FACE1_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'face1' failed with code %d", r);
  if (prezr_face1.numResources != PREZR_FACE1_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'face1' resource count mismatch");
}
void prezr_unload_face1() {
  prezr_destroy(&prezr_face1);
}
#else
extern prezr_pack_t prezr_face1;
extern void prezr_load_face1();
extern void prezr_unload_face1();
#endif // PREZR_IMPORT

// ------------------------- face2 -------------------------
#define PREZR_FACE2_CHECKSUM 0x96DCF9CD

typedef enum prezr_pack_face2_e {
  PREZR_FACE2_STFST20, // 24x30 Bit4Palettized
  PREZR_FACE2_STFST21, // 24x30 Bit8
  PREZR_FACE2_STFST22, // 24x30 Bit4Palettized
  PREZR_FACE2_COUNT
} prezr_pack_face2_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_FACE2_PACK)
prezr_pack_t prezr_face2;
void prezr_load_face2() {
  int r = prezr_init(&prezr_face2, RESOURCE_ID_PREZR_FACE2_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'face2' failed with code %d", r);
  if (prezr_face2.numResources != PREZR_FACE2_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'face2' resource count mismatch");
}
void prezr_unload_face2() {
  prezr_destroy(&prezr_face2);
}
#else
extern prezr_pack_t prezr_face2;
extern void prezr_load_face2();
extern void prezr_unload_face2();
#endif // PREZR_IMPORT

// ------------------------- face3 -------------------------
#define PREZR_FACE3_CHECKSUM 0x96DD6F09

typedef enum prezr_pack_face3_e {
  PREZR_FACE3_STFST30, // 24x31 Bit8
  PREZR_FACE3_STFST31, // 24x31 Bit8
  PREZR_FACE3_STFST32, // 24x31 Bit4Palettized
  PREZR_FACE3_COUNT
} prezr_pack_face3_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_FACE3_PACK)
prezr_pack_t prezr_face3;
void prezr_load_face3() {
  int r = prezr_init(&prezr_face3, RESOURCE_ID_PREZR_FACE3_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'face3' failed with code %d", r);
  if (prezr_face3.numResources != PREZR_FACE3_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'face3' resource count mismatch");
}
void prezr_unload_face3() {
  prezr_destroy(&prezr_face3);
}
#else
extern prezr_pack_t prezr_face3;
extern void prezr_load_face3();
extern void prezr_unload_face3();
#endif // PREZR_IMPORT

// ------------------------- face4 -------------------------
#define PREZR_FACE4_CHECKSUM 0x96DDBD2C

typedef enum prezr_pack_face4_e {
  PREZR_FACE4_STFST40, // 24x31 Bit8
  PREZR_FACE4_STFST41, // 24x31 Bit8
  PREZR_FACE4_STFST42, // 24x31 Bit4Palettized
  PREZR_FACE4_COUNT
} prezr_pack_face4_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_FACE4_PACK)
prezr_pack_t prezr_face4;
void prezr_load_face4() {
  int r = prezr_init(&prezr_face4, RESOURCE_ID_PREZR_FACE4_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'face4' failed with code %d", r);
  if (prezr_face4.numResources != PREZR_FACE4_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'face4' resource count mismatch");
}
void prezr_unload_face4() {
  prezr_destroy(&prezr_face4);
}
#else
extern prezr_pack_t prezr_face4;
extern void prezr_load_face4();
extern void prezr_unload_face4();
#endif // PREZR_IMPORT

// ------------------------- facebattery -------------------------
#define PREZR_FACEBATTERY_CHECKSUM 0x96DEA79C

typedef enum prezr_pack_facebattery_e {
  PREZR_FACEBATTERY_STFEVL0, // 24x30 Bit8
  PREZR_FACEBATTERY_STFEVL1, // 24x30 Bit8
  PREZR_FACEBATTERY_STFEVL2, // 24x30 Bit8
  PREZR_FACEBATTERY_STFEVL3, // 24x30 Bit8
  PREZR_FACEBATTERY_STFEVL4, // 24x30 Bit4Palettized
  PREZR_FACEBATTERY_STFGOD0, // 24x29 Bit4Palettized
  PREZR_FACEBATTERY_COUNT
} prezr_pack_facebattery_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_FACEBATTERY_PACK)
prezr_pack_t prezr_facebattery;
void prezr_load_facebattery() {
  int r = prezr_init(&prezr_facebattery, RESOURCE_ID_PREZR_FACEBATTERY_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'facebattery' failed with code %d", r);
  if (prezr_facebattery.numResources != PREZR_FACEBATTERY_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'facebattery' resource count mismatch");
}
void prezr_unload_facebattery() {
  prezr_destroy(&prezr_facebattery);
}
#else
extern prezr_pack_t prezr_facebattery;
extern void prezr_load_facebattery();
extern void prezr_unload_facebattery();
#endif // PREZR_IMPORT

// ------------------------- lamp_off -------------------------
#define PREZR_LAMP_OFF_CHECKSUM 0x96DEF5C6

typedef enum prezr_pack_lamp_off_e {
  PREZR_LAMP_OFF_TLP2BG1, // 21x60 Bit4Palettized
  PREZR_LAMP_OFF_COUNT
} prezr_pack_lamp_off_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_LAMP_OFF_PACK)
prezr_pack_t prezr_lamp_off;
void prezr_load_lamp_off() {
  int r = prezr_init(&prezr_lamp_off, RESOURCE_ID_PREZR_LAMP_OFF_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'lamp_off' failed with code %d", r);
  if (prezr_lamp_off.numResources != PREZR_LAMP_OFF_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'lamp_off' resource count mismatch");
}
void prezr_unload_lamp_off() {
  prezr_destroy(&prezr_lamp_off);
}
#else
extern prezr_pack_t prezr_lamp_off;
extern void prezr_load_lamp_off();
extern void prezr_unload_lamp_off();
#endif // PREZR_IMPORT

// ------------------------- lamp_on -------------------------
#define PREZR_LAMP_ON_CHECKSUM 0x96DF1CD9

typedef enum prezr_pack_lamp_on_e {
  PREZR_LAMP_ON_TLP2BG2, // 21x60 Bit8
  PREZR_LAMP_ON_COUNT
} prezr_pack_lamp_on_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_LAMP_ON_PACK)
prezr_pack_t prezr_lamp_on;
void prezr_load_lamp_on() {
  int r = prezr_init(&prezr_lamp_on, RESOURCE_ID_PREZR_LAMP_ON_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'lamp_on' failed with code %d", r);
  if (prezr_lamp_on.numResources != PREZR_LAMP_ON_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'lamp_on' resource count mismatch");
}
void prezr_unload_lamp_on() {
  prezr_destroy(&prezr_lamp_on);
}
#else
extern prezr_pack_t prezr_lamp_on;
extern void prezr_load_lamp_on();
extern void prezr_unload_lamp_on();
#endif // PREZR_IMPORT

// ------------------------- numerals -------------------------
#define PREZR_NUMERALS_CHECKSUM 0x96DFE030

typedef enum prezr_pack_numerals_e {
  PREZR_NUMERALS_STTNUM0, // 14x16 Bit4Palettized
  PREZR_NUMERALS_STTNUM1, // 11x16 Bit4Palettized
  PREZR_NUMERALS_STTNUM2, // 14x16 Bit4Palettized
  PREZR_NUMERALS_STTNUM3, // 14x16 Bit4Palettized
  PREZR_NUMERALS_STTNUM4, // 14x16 Bit4Palettized
  PREZR_NUMERALS_STTNUM5, // 14x16 Bit4Palettized
  PREZR_NUMERALS_STTNUM6, // 14x16 Bit4Palettized
  PREZR_NUMERALS_STTNUM7, // 14x16 Bit4Palettized
  PREZR_NUMERALS_STTNUM8, // 14x16 Bit4Palettized
  PREZR_NUMERALS_STTNUM9, // 14x16 Bit4Palettized
  PREZR_NUMERALS_COUNT
} prezr_pack_numerals_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_NUMERALS_PACK)
prezr_pack_t prezr_numerals;
void prezr_load_numerals() {
  int r = prezr_init(&prezr_numerals, RESOURCE_ID_PREZR_NUMERALS_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'numerals' failed with code %d", r);
  if (prezr_numerals.numResources != PREZR_NUMERALS_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'numerals' resource count mismatch");
}
void prezr_unload_numerals() {
  prezr_destroy(&prezr_numerals);
}
#else
extern prezr_pack_t prezr_numerals;
extern void prezr_load_numerals();
extern void prezr_unload_numerals();
#endif // PREZR_IMPORT

// ------------------------- playerdie -------------------------
#define PREZR_PLAYERDIE_CHECKSUM 0x96E118CD

typedef enum prezr_pack_playerdie_e {
  PREZR_PLAYERDIE_SPOSG1, // 31x55 Bit8
  PREZR_PLAYERDIE_SPOSH0, // 33x60 Bit8
  PREZR_PLAYERDIE_SPOSI0, // 35x50 Bit8
  PREZR_PLAYERDIE_SPOSJ0, // 42x35 Bit8
  PREZR_PLAYERDIE_SPOSK0, // 48x27 Bit8
  PREZR_PLAYERDIE_SPOSL0, // 52x17 Bit8
  PREZR_PLAYERDIE_COUNT
} prezr_pack_playerdie_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_PLAYERDIE_PACK)
prezr_pack_t prezr_playerdie;
void prezr_load_playerdie() {
  int r = prezr_init(&prezr_playerdie, RESOURCE_ID_PREZR_PLAYERDIE_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'playerdie' failed with code %d", r);
  if (prezr_playerdie.numResources != PREZR_PLAYERDIE_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'playerdie' resource count mismatch");
}
void prezr_unload_playerdie() {
  prezr_destroy(&prezr_playerdie);
}
#else
extern prezr_pack_t prezr_playerdie;
extern void prezr_load_playerdie();
extern void prezr_unload_playerdie();
#endif // PREZR_IMPORT

// ------------------------- playerwalk -------------------------
#define PREZR_PLAYERWALK_CHECKSUM 0x96E25217

typedef enum prezr_pack_playerwalk_e {
  PREZR_PLAYERWALK_SPOSA1, // 36x55 Bit8
  PREZR_PLAYERWALK_SPOSC1, // 32x55 Bit8
  PREZR_PLAYERWALK_COUNT
} prezr_pack_playerwalk_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_PLAYERWALK_PACK)
prezr_pack_t prezr_playerwalk;
void prezr_load_playerwalk() {
  int r = prezr_init(&prezr_playerwalk, RESOURCE_ID_PREZR_PLAYERWALK_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'playerwalk' failed with code %d", r);
  if (prezr_playerwalk.numResources != PREZR_PLAYERWALK_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'playerwalk' resource count mismatch");
}
void prezr_unload_playerwalk() {
  prezr_destroy(&prezr_playerwalk);
}
#else
extern prezr_pack_t prezr_playerwalk;
extern void prezr_load_playerwalk();
extern void prezr_unload_playerwalk();
#endif // PREZR_IMPORT

// ------------------------- respawn -------------------------
#define PREZR_RESPAWN_CHECKSUM 0x96E3B15D

typedef enum prezr_pack_respawn_e {
  PREZR_RESPAWN_TFOGA0, // 41x56 Bit8
  PREZR_RESPAWN_TFOGB0, // 42x45 Bit4Palettized
  PREZR_RESPAWN_TFOGC0, // 40x37 Bit4Palettized
  PREZR_RESPAWN_TFOGD0, // 30x34 Bit4Palettized
  PREZR_RESPAWN_TFOGE0, // 17x16 Bit4Palettized
  PREZR_RESPAWN_TFOGF0, // 9x8 Bit4Palettized
  PREZR_RESPAWN_TFOGG0, // 3x3 Bit2Palettized
  PREZR_RESPAWN_COUNT
} prezr_pack_respawn_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_RESPAWN_PACK)
prezr_pack_t prezr_respawn;
void prezr_load_respawn() {
  int r = prezr_init(&prezr_respawn, RESOURCE_ID_PREZR_RESPAWN_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'respawn' failed with code %d", r);
  if (prezr_respawn.numResources != PREZR_RESPAWN_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'respawn' resource count mismatch");
}
void prezr_unload_respawn() {
  prezr_destroy(&prezr_respawn);
}
#else
extern prezr_pack_t prezr_respawn;
extern void prezr_load_respawn();
extern void prezr_unload_respawn();
#endif // PREZR_IMPORT

// ------------------------- weaponfire1 -------------------------
#define PREZR_WEAPONFIRE1_CHECKSUM 0x96E55EEF

typedef enum prezr_pack_weaponfire1_e {
  PREZR_WEAPONFIRE1_SHTGB0, // 119x121 Bit8
  PREZR_WEAPONFIRE1_COUNT
} prezr_pack_weaponfire1_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_WEAPONFIRE1_PACK)
prezr_pack_t prezr_weaponfire1;
void prezr_load_weaponfire1() {
  int r = prezr_init(&prezr_weaponfire1, RESOURCE_ID_PREZR_WEAPONFIRE1_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'weaponfire1' failed with code %d", r);
  if (prezr_weaponfire1.numResources != PREZR_WEAPONFIRE1_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'weaponfire1' resource count mismatch");
}
void prezr_unload_weaponfire1() {
  prezr_destroy(&prezr_weaponfire1);
}
#else
extern prezr_pack_t prezr_weaponfire1;
extern void prezr_load_weaponfire1();
extern void prezr_unload_weaponfire1();
#endif // PREZR_IMPORT

// ------------------------- weaponfire2 -------------------------
#define PREZR_WEAPONFIRE2_CHECKSUM 0x96E733B2

typedef enum prezr_pack_weaponfire2_e {
  PREZR_WEAPONFIRE2_SHTGC0, // 87x151 Bit8
  PREZR_WEAPONFIRE2_COUNT
} prezr_pack_weaponfire2_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_WEAPONFIRE2_PACK)
prezr_pack_t prezr_weaponfire2;
void prezr_load_weaponfire2() {
  int r = prezr_init(&prezr_weaponfire2, RESOURCE_ID_PREZR_WEAPONFIRE2_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'weaponfire2' failed with code %d", r);
  if (prezr_weaponfire2.numResources != PREZR_WEAPONFIRE2_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'weaponfire2' resource count mismatch");
}
void prezr_unload_weaponfire2() {
  prezr_destroy(&prezr_weaponfire2);
}
#else
extern prezr_pack_t prezr_weaponfire2;
extern void prezr_load_weaponfire2();
extern void prezr_unload_weaponfire2();
#endif // PREZR_IMPORT

// ------------------------- weaponfire3 -------------------------
#define PREZR_WEAPONFIRE3_CHECKSUM 0x96E90896

typedef enum prezr_pack_weaponfire3_e {
  PREZR_WEAPONFIRE3_SHTGD0, // 113x131 Bit8
  PREZR_WEAPONFIRE3_COUNT
} prezr_pack_weaponfire3_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_WEAPONFIRE3_PACK)
prezr_pack_t prezr_weaponfire3;
void prezr_load_weaponfire3() {
  int r = prezr_init(&prezr_weaponfire3, RESOURCE_ID_PREZR_WEAPONFIRE3_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'weaponfire3' failed with code %d", r);
  if (prezr_weaponfire3.numResources != PREZR_WEAPONFIRE3_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'weaponfire3' resource count mismatch");
}
void prezr_unload_weaponfire3() {
  prezr_destroy(&prezr_weaponfire3);
}
#else
extern prezr_pack_t prezr_weaponfire3;
extern void prezr_load_weaponfire3();
extern void prezr_unload_weaponfire3();
#endif // PREZR_IMPORT

// ------------------------- weaponstatic -------------------------
#define PREZR_WEAPONSTATIC_CHECKSUM 0x96E9F300

typedef enum prezr_pack_weaponstatic_e {
  PREZR_WEAPONSTATIC_SHTFA0, // 44x31 Bit4Palettized
  PREZR_WEAPONSTATIC_SHTGA0, // 79x60 Bit8
  PREZR_WEAPONSTATIC_COUNT
} prezr_pack_weaponstatic_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_WEAPONSTATIC_PACK)
prezr_pack_t prezr_weaponstatic;
void prezr_load_weaponstatic() {
  int r = prezr_init(&prezr_weaponstatic, RESOURCE_ID_PREZR_WEAPONSTATIC_PACK);
  if (r != PREZR_OK)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'weaponstatic' failed with code %d", r);
  if (prezr_weaponstatic.numResources != PREZR_WEAPONSTATIC_COUNT)
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'weaponstatic' resource count mismatch");
}
void prezr_unload_weaponstatic() {
  prezr_destroy(&prezr_weaponstatic);
}
#else
extern prezr_pack_t prezr_weaponstatic;
extern void prezr_load_weaponstatic();
extern void prezr_unload_weaponstatic();
#endif // PREZR_IMPORT

