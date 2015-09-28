#pragma once

// ------------------------- background -------------------------
typedef enum prezr_pack_background_e {
  PREZR_BACKGROUND_BACKGROUND, // 144x136 Bit8
  PREZR_BACKGROUND_STATUSBAR, // 144x32 Bit2Palettized
  PREZR_BACKGROUND_COUNT
} prezr_pack_background_t;

// ------------------------- face0 -------------------------
typedef enum prezr_pack_face0_e {
  PREZR_FACE0_STFST00, // 24x29 Bit4Palettized
  PREZR_FACE0_STFST01, // 24x29 Bit4Palettized
  PREZR_FACE0_STFST02, // 24x29 Bit4Palettized
  PREZR_FACE0_COUNT
} prezr_pack_face0_t;

// ------------------------- face1 -------------------------
typedef enum prezr_pack_face1_e {
  PREZR_FACE1_STFST10, // 24x29 Bit4Palettized
  PREZR_FACE1_STFST11, // 24x29 Bit8
  PREZR_FACE1_STFST12, // 24x29 Bit4Palettized
  PREZR_FACE1_COUNT
} prezr_pack_face1_t;

// ------------------------- face2 -------------------------
typedef enum prezr_pack_face2_e {
  PREZR_FACE2_STFST20, // 24x30 Bit4Palettized
  PREZR_FACE2_STFST21, // 24x30 Bit8
  PREZR_FACE2_STFST22, // 24x30 Bit4Palettized
  PREZR_FACE2_COUNT
} prezr_pack_face2_t;

// ------------------------- face3 -------------------------
typedef enum prezr_pack_face3_e {
  PREZR_FACE3_STFST30, // 24x31 Bit8
  PREZR_FACE3_STFST31, // 24x31 Bit8
  PREZR_FACE3_STFST32, // 24x31 Bit4Palettized
  PREZR_FACE3_COUNT
} prezr_pack_face3_t;

// ------------------------- face4 -------------------------
typedef enum prezr_pack_face4_e {
  PREZR_FACE4_STFST40, // 24x31 Bit8
  PREZR_FACE4_STFST41, // 24x31 Bit8
  PREZR_FACE4_STFST42, // 24x31 Bit4Palettized
  PREZR_FACE4_COUNT
} prezr_pack_face4_t;

// ------------------------- facebattery -------------------------
typedef enum prezr_pack_facebattery_e {
  PREZR_FACEBATTERY_STFEVL0, // 24x30 Bit8
  PREZR_FACEBATTERY_STFEVL1, // 24x30 Bit8
  PREZR_FACEBATTERY_STFEVL2, // 24x30 Bit8
  PREZR_FACEBATTERY_STFEVL3, // 24x30 Bit8
  PREZR_FACEBATTERY_STFEVL4, // 24x30 Bit4Palettized
  PREZR_FACEBATTERY_STFGOD0, // 24x29 Bit4Palettized
  PREZR_FACEBATTERY_COUNT
} prezr_pack_facebattery_t;

// ------------------------- lamp_off -------------------------
typedef enum prezr_pack_lamp_off_e {
  PREZR_LAMP_OFF_TLP2BG1, // 21x60 Bit4Palettized
  PREZR_LAMP_OFF_COUNT
} prezr_pack_lamp_off_t;

// ------------------------- lamp_on -------------------------
typedef enum prezr_pack_lamp_on_e {
  PREZR_LAMP_ON_TLP2BG2, // 21x60 Bit8
  PREZR_LAMP_ON_COUNT
} prezr_pack_lamp_on_t;

// ------------------------- logo -------------------------
typedef enum prezr_pack_logo_e {
  PREZR_LOGO_STFKILL1, // 28x28 Bit8
  PREZR_LOGO_COUNT
} prezr_pack_logo_t;

// ------------------------- numerals -------------------------
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

// ------------------------- playerdie -------------------------
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

// ------------------------- playerwalk -------------------------
typedef enum prezr_pack_playerwalk_e {
  PREZR_PLAYERWALK_PLAYA1, // 41x56 Bit8
  PREZR_PLAYERWALK_PLAYC1, // 38x56 Bit4Palettized
  PREZR_PLAYERWALK_COUNT
} prezr_pack_playerwalk_t;

// ------------------------- respawn -------------------------
typedef enum prezr_pack_respawn_e {
  PREZR_RESPAWN_TFOGA0, // 41x56 Bit8
  PREZR_RESPAWN_TFOGB0, // 42x45 Bit4Palettized
  PREZR_RESPAWN_TFOGC0, // 40x37 Bit4Palettized
  PREZR_RESPAWN_TFOGD0, // 30x34 Bit4Palettized
  PREZR_RESPAWN_TFOGE0, // 17x16 Bit4Palettized
  PREZR_RESPAWN_TFOGF0, // 9x8 Bit4Palettized
  PREZR_RESPAWN_TFOGG0, // 3x3 Bit2Palettized
  PREZR_RESPAWN_TFOGH0, // 7x7 Bit4Palettized
  PREZR_RESPAWN_TFOGI0, // 13x13 Bit4Palettized
  PREZR_RESPAWN_TFOGJ0, // 17x17 Bit4Palettized
  PREZR_RESPAWN_COUNT
} prezr_pack_respawn_t;

// ------------------------- sg_fire1 -------------------------
typedef enum prezr_pack_sg_fire1_e {
  PREZR_SG_FIRE1_SHTGB0, // 119x121 Bit8
  PREZR_SG_FIRE1_COUNT
} prezr_pack_sg_fire1_t;

// ------------------------- sg_fire2 -------------------------
typedef enum prezr_pack_sg_fire2_e {
  PREZR_SG_FIRE2_SHTGC0, // 87x151 Bit8
  PREZR_SG_FIRE2_COUNT
} prezr_pack_sg_fire2_t;

// ------------------------- sg_fire3 -------------------------
typedef enum prezr_pack_sg_fire3_e {
  PREZR_SG_FIRE3_SHTGD0, // 113x131 Bit8
  PREZR_SG_FIRE3_COUNT
} prezr_pack_sg_fire3_t;

// ------------------------- sg_static -------------------------
typedef enum prezr_pack_sg_static_e {
  PREZR_SG_STATIC_SHTFA0, // 44x31 Bit4Palettized
  PREZR_SG_STATIC_SHTGA0, // 79x60 Bit8
  PREZR_SG_STATIC_COUNT
} prezr_pack_sg_static_t;

// ------------------------- ss_fire1 -------------------------
typedef enum prezr_pack_ss_fire1_e {
  PREZR_SS_FIRE1_SHT2I0, // 55x37 Bit8
  PREZR_SS_FIRE1_COUNT
} prezr_pack_ss_fire1_t;

// ------------------------- ss_fire2 -------------------------
typedef enum prezr_pack_ss_fire2_e {
  PREZR_SS_FIRE2_SHT2J0, // 65x46 Bit8
  PREZR_SS_FIRE2_COUNT
} prezr_pack_ss_fire2_t;

// ------------------------- ss_fire3 -------------------------
typedef enum prezr_pack_ss_fire3_e {
  PREZR_SS_FIRE3_SHT2B0, // 83x103 Bit8
  PREZR_SS_FIRE3_COUNT
} prezr_pack_ss_fire3_t;

// ------------------------- ss_fire4 -------------------------
typedef enum prezr_pack_ss_fire4_e {
  PREZR_SS_FIRE4_SHT2C0, // 121x130 Bit8
  PREZR_SS_FIRE4_COUNT
} prezr_pack_ss_fire4_t;

// ------------------------- ss_fire5 -------------------------
typedef enum prezr_pack_ss_fire5_e {
  PREZR_SS_FIRE5_SHT2D0, // 81x80 Bit8
  PREZR_SS_FIRE5_COUNT
} prezr_pack_ss_fire5_t;

// ------------------------- ss_fire6 -------------------------
typedef enum prezr_pack_ss_fire6_e {
  PREZR_SS_FIRE6_SHT2E0, // 201x63 Bit8
  PREZR_SS_FIRE6_COUNT
} prezr_pack_ss_fire6_t;

// ------------------------- ss_fire7 -------------------------
typedef enum prezr_pack_ss_fire7_e {
  PREZR_SS_FIRE7_SHT2F0, // 88x51 Bit8
  PREZR_SS_FIRE7_COUNT
} prezr_pack_ss_fire7_t;

// ------------------------- ss_fire8 -------------------------
typedef enum prezr_pack_ss_fire8_e {
  PREZR_SS_FIRE8_SHT2G0, // 81x80 Bit8
  PREZR_SS_FIRE8_COUNT
} prezr_pack_ss_fire8_t;

// ------------------------- ss_fire9 -------------------------
typedef enum prezr_pack_ss_fire9_e {
  PREZR_SS_FIRE9_SHT2H0, // 77x85 Bit8
  PREZR_SS_FIRE9_COUNT
} prezr_pack_ss_fire9_t;

// ------------------------- ss_static -------------------------
typedef enum prezr_pack_ss_static_e {
  PREZR_SS_STATIC_SHT2A0, // 59x55 Bit4Palettized
  PREZR_SS_STATIC_COUNT
} prezr_pack_ss_static_t;

// ------------------------- zombiedie -------------------------
typedef enum prezr_pack_zombiedie_e {
  PREZR_ZOMBIEDIE_SPOSG1, // 31x55 Bit8
  PREZR_ZOMBIEDIE_SPOSH0, // 33x60 Bit8
  PREZR_ZOMBIEDIE_SPOSI0, // 35x50 Bit8
  PREZR_ZOMBIEDIE_SPOSJ0, // 42x35 Bit8
  PREZR_ZOMBIEDIE_SPOSK0, // 48x27 Bit8
  PREZR_ZOMBIEDIE_SPOSL0, // 52x17 Bit8
  PREZR_ZOMBIEDIE_COUNT
} prezr_pack_zombiedie_t;

// ------------------------- zombiewalk -------------------------
typedef enum prezr_pack_zombiewalk_e {
  PREZR_ZOMBIEWALK_SPOSA1, // 36x55 Bit8
  PREZR_ZOMBIEWALK_SPOSC1, // 32x55 Bit8
  PREZR_ZOMBIEWALK_COUNT
} prezr_pack_zombiewalk_t;


