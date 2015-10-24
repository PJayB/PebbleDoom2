#include <pebble.h>
#include "doom.h"
  
void tap_handler(AccelAxisType axis, int32_t direction) {
  switch (axis) {
  case ACCEL_AXIS_Z:
    if (direction < 0) {
      doom_play_kill_animation();
    }
    break;
  default:
    break;
  }
}

void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  if ((units_changed & MINUTE_UNIT) != 0) {
    doom_time_changed(tick_time);
    doom_play_kill_animation();
  } else if ((units_changed & SECOND_UNIT) != 0) {
    doom_animate();
  }
}

void battery_handler(BatteryChargeState state) {
  doom_battery_level_changed(state.charge_percent, state.is_charging);
}

void bluetooth_handler(bool state) {
  doom_bluetooth_changed(state);
}
 
int main(void) {
  
  time_t time_now;
  time(&time_now);
  struct tm* localtime_now = localtime(&time_now);

  BatteryChargeState battery = battery_state_service_peek();
  
  bool bt = bluetooth_connection_service_peek();
  
  doom_init(localtime_now, battery.charge_percent, battery.is_charging, bt);
  tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
  battery_state_service_subscribe(battery_handler);
  bluetooth_connection_service_subscribe(bluetooth_handler);
  accel_tap_service_subscribe(tap_handler);
    
  app_event_loop();
  doom_destroy();
}
