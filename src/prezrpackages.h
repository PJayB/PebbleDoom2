#pragma once

// ------------------------- background -------------------------
#define PREZR_BACKGROUND_CHECKSUM 0xB6FC6867

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
#define PREZR_FACE0_CHECKSUM 0xB6FD66A9

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
#define PREZR_FACE1_CHECKSUM 0xB6FDC87A

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
#define PREZR_FACE2_CHECKSUM 0xB6FE3DD8

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
#define PREZR_FACE3_CHECKSUM 0xB6FE9FA9

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
#define PREZR_FACE4_CHECKSUM 0xB6FF0175

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
#define PREZR_FACEBATTERY_CHECKSUM 0xB6FFB18C

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
#define PREZR_LAMP_OFF_CHECKSUM 0xB700134E

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
#define PREZR_LAMP_ON_CHECKSUM 0xB7004DFD

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

// ------------------------- logo -------------------------
#define PREZR_LOGO_CHECKSUM 0xB70088AF

typedef enum prezr_pack_logo_e {
    PREZR_LOGO_STFKILL1, // 28x28 Bit8
    PREZR_LOGO_COUNT
} prezr_pack_logo_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_LOGO_PACK)
prezr_pack_t prezr_logo;
void prezr_load_logo() {
    int r = prezr_init(&prezr_logo, RESOURCE_ID_PREZR_LOGO_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'logo' failed with code %d", r);
    if (prezr_logo.numResources != PREZR_LOGO_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'logo' resource count mismatch");
}
void prezr_unload_logo() {
    prezr_destroy(&prezr_logo);
}
#else
extern prezr_pack_t prezr_logo;
extern void prezr_load_logo();
extern void prezr_unload_logo();
#endif // PREZR_IMPORT

// ------------------------- numerals -------------------------
#define PREZR_NUMERALS_CHECKSUM 0xB70138BF

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
#define PREZR_PLAYERDIE_CHECKSUM 0xB702BFF6

typedef enum prezr_pack_playerdie_e {
    PREZR_PLAYERDIE_PLAYG1, // 39x55 Bit8
    PREZR_PLAYERDIE_PLAYH0, // 44x50 Bit8
    PREZR_PLAYERDIE_PLAYI0, // 35x43 Bit8
    PREZR_PLAYERDIE_PLAYJ0, // 36x46 Bit8
    PREZR_PLAYERDIE_PLAYK0, // 41x38 Bit8
    PREZR_PLAYERDIE_PLAYL0, // 51x14 Bit8
    PREZR_PLAYERDIE_PLAYM0, // 51x14 Bit8
    PREZR_PLAYERDIE_PLAYN0, // 51x14 Bit8
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
#define PREZR_PLAYERWALK_CHECKSUM 0xB7035C79

typedef enum prezr_pack_playerwalk_e {
    PREZR_PLAYERWALK_PLAYA1, // 41x56 Bit8
    PREZR_PLAYERWALK_PLAYC1, // 38x56 Bit4Palettized
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
#define PREZR_RESPAWN_CHECKSUM 0xB7046E5C

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

// ------------------------- sg_fire1 -------------------------
#define PREZR_SG_FIRE1_CHECKSUM 0xB705F591

typedef enum prezr_pack_sg_fire1_e {
    PREZR_SG_FIRE1_SHTGB0, // 119x121 Bit8
    PREZR_SG_FIRE1_COUNT
} prezr_pack_sg_fire1_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SG_FIRE1_PACK)
prezr_pack_t prezr_sg_fire1;
void prezr_load_sg_fire1() {
    int r = prezr_init(&prezr_sg_fire1, RESOURCE_ID_PREZR_SG_FIRE1_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'sg_fire1' failed with code %d", r);
    if (prezr_sg_fire1.numResources != PREZR_SG_FIRE1_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'sg_fire1' resource count mismatch");
}
void prezr_unload_sg_fire1() {
    prezr_destroy(&prezr_sg_fire1);
}
#else
extern prezr_pack_t prezr_sg_fire1;
extern void prezr_load_sg_fire1();
extern void prezr_unload_sg_fire1();
#endif // PREZR_IMPORT

// ------------------------- sg_fire2 -------------------------
#define PREZR_SG_FIRE2_CHECKSUM 0xB707693E

typedef enum prezr_pack_sg_fire2_e {
    PREZR_SG_FIRE2_SHTGC0, // 87x151 Bit8
    PREZR_SG_FIRE2_COUNT
} prezr_pack_sg_fire2_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SG_FIRE2_PACK)
prezr_pack_t prezr_sg_fire2;
void prezr_load_sg_fire2() {
    int r = prezr_init(&prezr_sg_fire2, RESOURCE_ID_PREZR_SG_FIRE2_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'sg_fire2' failed with code %d", r);
    if (prezr_sg_fire2.numResources != PREZR_SG_FIRE2_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'sg_fire2' resource count mismatch");
}
void prezr_unload_sg_fire2() {
    prezr_destroy(&prezr_sg_fire2);
}
#else
extern prezr_pack_t prezr_sg_fire2;
extern void prezr_load_sg_fire2();
extern void prezr_unload_sg_fire2();
#endif // PREZR_IMPORT

// ------------------------- sg_fire3 -------------------------
#define PREZR_SG_FIRE3_CHECKSUM 0xB7093EAA

typedef enum prezr_pack_sg_fire3_e {
    PREZR_SG_FIRE3_SHTGD0, // 113x131 Bit8
    PREZR_SG_FIRE3_COUNT
} prezr_pack_sg_fire3_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SG_FIRE3_PACK)
prezr_pack_t prezr_sg_fire3;
void prezr_load_sg_fire3() {
    int r = prezr_init(&prezr_sg_fire3, RESOURCE_ID_PREZR_SG_FIRE3_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'sg_fire3' failed with code %d", r);
    if (prezr_sg_fire3.numResources != PREZR_SG_FIRE3_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'sg_fire3' resource count mismatch");
}
void prezr_unload_sg_fire3() {
    prezr_destroy(&prezr_sg_fire3);
}
#else
extern prezr_pack_t prezr_sg_fire3;
extern void prezr_load_sg_fire3();
extern void prezr_unload_sg_fire3();
#endif // PREZR_IMPORT

// ------------------------- sg_static -------------------------
#define PREZR_SG_STATIC_CHECKSUM 0xB70A2969

typedef enum prezr_pack_sg_static_e {
    PREZR_SG_STATIC_SHTFA0, // 44x31 Bit4Palettized
    PREZR_SG_STATIC_SHTGA0, // 79x60 Bit8
    PREZR_SG_STATIC_COUNT
} prezr_pack_sg_static_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SG_STATIC_PACK)
prezr_pack_t prezr_sg_static;
void prezr_load_sg_static() {
    int r = prezr_init(&prezr_sg_static, RESOURCE_ID_PREZR_SG_STATIC_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'sg_static' failed with code %d", r);
    if (prezr_sg_static.numResources != PREZR_SG_STATIC_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'sg_static' resource count mismatch");
}
void prezr_unload_sg_static() {
    prezr_destroy(&prezr_sg_static);
}
#else
extern prezr_pack_t prezr_sg_static;
extern void prezr_load_sg_static();
extern void prezr_unload_sg_static();
#endif // PREZR_IMPORT

// ------------------------- ss_fire1 -------------------------
#define PREZR_SS_FIRE1_CHECKSUM 0xB70A77A8

typedef enum prezr_pack_ss_fire1_e {
    PREZR_SS_FIRE1_SHT2I0, // 55x37 Bit8
    PREZR_SS_FIRE1_COUNT
} prezr_pack_ss_fire1_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SS_FIRE1_PACK)
prezr_pack_t prezr_ss_fire1;
void prezr_load_ss_fire1() {
    int r = prezr_init(&prezr_ss_fire1, RESOURCE_ID_PREZR_SS_FIRE1_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire1' failed with code %d", r);
    if (prezr_ss_fire1.numResources != PREZR_SS_FIRE1_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire1' resource count mismatch");
}
void prezr_unload_ss_fire1() {
    prezr_destroy(&prezr_ss_fire1);
}
#else
extern prezr_pack_t prezr_ss_fire1;
extern void prezr_load_ss_fire1();
extern void prezr_unload_ss_fire1();
#endif // PREZR_IMPORT

// ------------------------- ss_fire2 -------------------------
#define PREZR_SS_FIRE2_CHECKSUM 0xB70AED06

typedef enum prezr_pack_ss_fire2_e {
    PREZR_SS_FIRE2_SHT2J0, // 65x46 Bit8
    PREZR_SS_FIRE2_COUNT
} prezr_pack_ss_fire2_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SS_FIRE2_PACK)
prezr_pack_t prezr_ss_fire2;
void prezr_load_ss_fire2() {
    int r = prezr_init(&prezr_ss_fire2, RESOURCE_ID_PREZR_SS_FIRE2_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire2' failed with code %d", r);
    if (prezr_ss_fire2.numResources != PREZR_SS_FIRE2_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire2' resource count mismatch");
}
void prezr_unload_ss_fire2() {
    prezr_destroy(&prezr_ss_fire2);
}
#else
extern prezr_pack_t prezr_ss_fire2;
extern void prezr_load_ss_fire2();
extern void prezr_unload_ss_fire2();
#endif // PREZR_IMPORT

// ------------------------- ss_fire3 -------------------------
#define PREZR_SS_FIRE3_CHECKSUM 0xB70BEB52

typedef enum prezr_pack_ss_fire3_e {
    PREZR_SS_FIRE3_SHT2B0, // 83x103 Bit8
    PREZR_SS_FIRE3_COUNT
} prezr_pack_ss_fire3_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SS_FIRE3_PACK)
prezr_pack_t prezr_ss_fire3;
void prezr_load_ss_fire3() {
    int r = prezr_init(&prezr_ss_fire3, RESOURCE_ID_PREZR_SS_FIRE3_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire3' failed with code %d", r);
    if (prezr_ss_fire3.numResources != PREZR_SS_FIRE3_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire3' resource count mismatch");
}
void prezr_unload_ss_fire3() {
    prezr_destroy(&prezr_ss_fire3);
}
#else
extern prezr_pack_t prezr_ss_fire3;
extern void prezr_load_ss_fire3();
extern void prezr_unload_ss_fire3();
#endif // PREZR_IMPORT

// ------------------------- ss_fire4 -------------------------
#define PREZR_SS_FIRE4_CHECKSUM 0xB70D8619

typedef enum prezr_pack_ss_fire4_e {
    PREZR_SS_FIRE4_SHT2C0, // 121x130 Bit8
    PREZR_SS_FIRE4_COUNT
} prezr_pack_ss_fire4_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SS_FIRE4_PACK)
prezr_pack_t prezr_ss_fire4;
void prezr_load_ss_fire4() {
    int r = prezr_init(&prezr_ss_fire4, RESOURCE_ID_PREZR_SS_FIRE4_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire4' failed with code %d", r);
    if (prezr_ss_fire4.numResources != PREZR_SS_FIRE4_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire4' resource count mismatch");
}
void prezr_unload_ss_fire4() {
    prezr_destroy(&prezr_ss_fire4);
}
#else
extern prezr_pack_t prezr_ss_fire4;
extern void prezr_load_ss_fire4();
extern void prezr_unload_ss_fire4();
#endif // PREZR_IMPORT

// ------------------------- ss_fire5 -------------------------
#define PREZR_SS_FIRE5_CHECKSUM 0xB70E49B9

typedef enum prezr_pack_ss_fire5_e {
    PREZR_SS_FIRE5_SHT2D0, // 81x80 Bit8
    PREZR_SS_FIRE5_COUNT
} prezr_pack_ss_fire5_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SS_FIRE5_PACK)
prezr_pack_t prezr_ss_fire5;
void prezr_load_ss_fire5() {
    int r = prezr_init(&prezr_ss_fire5, RESOURCE_ID_PREZR_SS_FIRE5_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire5' failed with code %d", r);
    if (prezr_ss_fire5.numResources != PREZR_SS_FIRE5_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire5' resource count mismatch");
}
void prezr_unload_ss_fire5() {
    prezr_destroy(&prezr_ss_fire5);
}
#else
extern prezr_pack_t prezr_ss_fire5;
extern void prezr_load_ss_fire5();
extern void prezr_unload_ss_fire5();
#endif // PREZR_IMPORT

// ------------------------- ss_fire6 -------------------------
#define PREZR_SS_FIRE6_CHECKSUM 0xB70FD0F1

typedef enum prezr_pack_ss_fire6_e {
    PREZR_SS_FIRE6_SHT2E0, // 201x63 Bit8
    PREZR_SS_FIRE6_COUNT
} prezr_pack_ss_fire6_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SS_FIRE6_PACK)
prezr_pack_t prezr_ss_fire6;
void prezr_load_ss_fire6() {
    int r = prezr_init(&prezr_ss_fire6, RESOURCE_ID_PREZR_SS_FIRE6_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire6' failed with code %d", r);
    if (prezr_ss_fire6.numResources != PREZR_SS_FIRE6_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire6' resource count mismatch");
}
void prezr_unload_ss_fire6() {
    prezr_destroy(&prezr_ss_fire6);
}
#else
extern prezr_pack_t prezr_ss_fire6;
extern void prezr_load_ss_fire6();
extern void prezr_unload_ss_fire6();
#endif // PREZR_IMPORT

// ------------------------- ss_fire7 -------------------------
#define PREZR_SS_FIRE7_CHECKSUM 0xB7108100

typedef enum prezr_pack_ss_fire7_e {
    PREZR_SS_FIRE7_SHT2F0, // 88x51 Bit8
    PREZR_SS_FIRE7_COUNT
} prezr_pack_ss_fire7_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SS_FIRE7_PACK)
prezr_pack_t prezr_ss_fire7;
void prezr_load_ss_fire7() {
    int r = prezr_init(&prezr_ss_fire7, RESOURCE_ID_PREZR_SS_FIRE7_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire7' failed with code %d", r);
    if (prezr_ss_fire7.numResources != PREZR_SS_FIRE7_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire7' resource count mismatch");
}
void prezr_unload_ss_fire7() {
    prezr_destroy(&prezr_ss_fire7);
}
#else
extern prezr_pack_t prezr_ss_fire7;
extern void prezr_load_ss_fire7();
extern void prezr_unload_ss_fire7();
#endif // PREZR_IMPORT

// ------------------------- ss_fire8 -------------------------
#define PREZR_SS_FIRE8_CHECKSUM 0xB711449D

typedef enum prezr_pack_ss_fire8_e {
    PREZR_SS_FIRE8_SHT2G0, // 81x80 Bit8
    PREZR_SS_FIRE8_COUNT
} prezr_pack_ss_fire8_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SS_FIRE8_PACK)
prezr_pack_t prezr_ss_fire8;
void prezr_load_ss_fire8() {
    int r = prezr_init(&prezr_ss_fire8, RESOURCE_ID_PREZR_SS_FIRE8_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire8' failed with code %d", r);
    if (prezr_ss_fire8.numResources != PREZR_SS_FIRE8_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire8' resource count mismatch");
}
void prezr_unload_ss_fire8() {
    prezr_destroy(&prezr_ss_fire8);
}
#else
extern prezr_pack_t prezr_ss_fire8;
extern void prezr_load_ss_fire8();
extern void prezr_unload_ss_fire8();
#endif // PREZR_IMPORT

// ------------------------- ss_fire9 -------------------------
#define PREZR_SS_FIRE9_CHECKSUM 0xB712083A

typedef enum prezr_pack_ss_fire9_e {
    PREZR_SS_FIRE9_SHT2H0, // 77x85 Bit8
    PREZR_SS_FIRE9_COUNT
} prezr_pack_ss_fire9_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SS_FIRE9_PACK)
prezr_pack_t prezr_ss_fire9;
void prezr_load_ss_fire9() {
    int r = prezr_init(&prezr_ss_fire9, RESOURCE_ID_PREZR_SS_FIRE9_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire9' failed with code %d", r);
    if (prezr_ss_fire9.numResources != PREZR_SS_FIRE9_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_fire9' resource count mismatch");
}
void prezr_unload_ss_fire9() {
    prezr_destroy(&prezr_ss_fire9);
}
#else
extern prezr_pack_t prezr_ss_fire9;
extern void prezr_load_ss_fire9();
extern void prezr_unload_ss_fire9();
#endif // PREZR_IMPORT

// ------------------------- ss_static -------------------------
#define PREZR_SS_STATIC_CHECKSUM 0xB7126A06

typedef enum prezr_pack_ss_static_e {
    PREZR_SS_STATIC_SHT2A0, // 59x55 Bit4Palettized
    PREZR_SS_STATIC_COUNT
} prezr_pack_ss_static_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_SS_STATIC_PACK)
prezr_pack_t prezr_ss_static;
void prezr_load_ss_static() {
    int r = prezr_init(&prezr_ss_static, RESOURCE_ID_PREZR_SS_STATIC_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_static' failed with code %d", r);
    if (prezr_ss_static.numResources != PREZR_SS_STATIC_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'ss_static' resource count mismatch");
}
void prezr_unload_ss_static() {
    prezr_destroy(&prezr_ss_static);
}
#else
extern prezr_pack_t prezr_ss_static;
extern void prezr_load_ss_static();
extern void prezr_unload_ss_static();
#endif // PREZR_IMPORT

// ------------------------- zombiewalk -------------------------
#define PREZR_ZOMBIEWALK_CHECKSUM 0xB7130942

typedef enum prezr_pack_zombiewalk_e {
    PREZR_ZOMBIEWALK_SPOSA1, // 36x55 Bit8
    PREZR_ZOMBIEWALK_SPOSC1, // 32x55 Bit8
    PREZR_ZOMBIEWALK_COUNT
} prezr_pack_zombiewalk_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_ZOMBIEWALK_PACK)
prezr_pack_t prezr_zombiewalk;
void prezr_load_zombiewalk() {
    int r = prezr_init(&prezr_zombiewalk, RESOURCE_ID_PREZR_ZOMBIEWALK_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'zombiewalk' failed with code %d", r);
    if (prezr_zombiewalk.numResources != PREZR_ZOMBIEWALK_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'zombiewalk' resource count mismatch");
}
void prezr_unload_zombiewalk() {
    prezr_destroy(&prezr_zombiewalk);
}
#else
extern prezr_pack_t prezr_zombiewalk;
extern void prezr_load_zombiewalk();
extern void prezr_unload_zombiewalk();
#endif // PREZR_IMPORT

// ------------------------- zomebiedie -------------------------
#define PREZR_ZOMEBIEDIE_CHECKSUM 0xB71441D7

typedef enum prezr_pack_zomebiedie_e {
    PREZR_ZOMEBIEDIE_SPOSG1, // 31x55 Bit8
    PREZR_ZOMEBIEDIE_SPOSH0, // 33x60 Bit8
    PREZR_ZOMEBIEDIE_SPOSI0, // 35x50 Bit8
    PREZR_ZOMEBIEDIE_SPOSJ0, // 42x35 Bit8
    PREZR_ZOMEBIEDIE_SPOSK0, // 48x27 Bit8
    PREZR_ZOMEBIEDIE_SPOSL0, // 52x17 Bit8
    PREZR_ZOMEBIEDIE_COUNT
} prezr_pack_zomebiedie_t;

#if defined(PREZR_IMPORT) || defined(PREZR_IMPORT_ZOMEBIEDIE_PACK)
prezr_pack_t prezr_zomebiedie;
void prezr_load_zomebiedie() {
    int r = prezr_init(&prezr_zomebiedie, RESOURCE_ID_PREZR_ZOMEBIEDIE_PACK);
    if (r != PREZR_OK)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'zomebiedie' failed with code %d", r);
    if (prezr_zomebiedie.numResources != PREZR_ZOMEBIEDIE_COUNT)
        APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package 'zomebiedie' resource count mismatch");
}
void prezr_unload_zomebiedie() {
    prezr_destroy(&prezr_zomebiedie);
}
#else
extern prezr_pack_t prezr_zomebiedie;
extern void prezr_load_zomebiedie();
extern void prezr_unload_zomebiedie();
#endif // PREZR_IMPORT

