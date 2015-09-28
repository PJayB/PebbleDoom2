#include <pebble.h>
#include "spritehelpers.h"

void image_center(Layer* layer, GPoint location, GSize size) {
    int16_t x = location.x - size.w / 2;
    int16_t y = location.y - size.h / 2;

    GRect rect = {
        {x, y,},
        size
    };

    layer_set_frame(layer, rect);
}

void image_center_bottom(Layer* layer, GPoint location, GSize size) {
    int16_t x = location.x - size.w / 2;
    int16_t y = location.y - size.h;

    GRect rect = {
        {x, y,},
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



