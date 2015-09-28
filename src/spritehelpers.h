#pragma once

void image_center(Layer* layer, GPoint location, GSize size);
void image_center_bottom(Layer* layer, GPoint location, GSize size);
void set_image_and_center(BitmapLayer* layer, const prezr_bitmap_t* resource, GPoint location);
void set_image_and_center_bottom(BitmapLayer* layer, const prezr_bitmap_t* resource, GPoint location);
