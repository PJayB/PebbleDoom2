#pragma once

void doom_init(struct tm* init_time, uint8_t batteryPercent, bool isCharging, bool hasBluetooth);
void doom_destroy(void);
void doom_time_changed(struct tm *tick_time);
void doom_animate(void);
void doom_battery_level_changed(uint8_t percent, bool charging);
void doom_bluetooth_changed(bool connected);
void doom_play_animation(void);

