#include <pebble.h>
#include "prezr.h"
#include "packhelpers.h"

void _load_pack(const char* name, prezr_pack_t* pack, uint32_t resource_id) {
  unload_pack(pack);
  int r = prezr_init(pack, resource_id);
  if (r != PREZR_OK) {
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package '%s' failed with code %d", name, r);
  }
}
void _load_pack_placement(const char* name, prezr_pack_t* pack, uint32_t resource_id, void* heap, size_t heap_size) {
  unload_pack_placement(pack);
  int r = prezr_placement_init(pack, resource_id, heap, heap_size);
  if (r != PREZR_OK) {
    APP_LOG(APP_LOG_LEVEL_ERROR, "PRezr package '%s' failed with code %d", name, r);
  }
}

void unload_pack(prezr_pack_t* pack) {
    prezr_destroy(pack);
}
void unload_pack_placement(prezr_pack_t* pack) {
    prezr_placement_destroy(pack);
}

size_t get_resource_size(uint32_t resource_id) {
  return resource_size(resource_get_handle(resource_id));
}

void _init_shared_placement_block(const char* name, placement_block_t* block, const size_t* sizes, size_t num_resources) {
  // Get the max size
  size_t size = 0;
  for (size_t i = 0; i < num_resources; ++i) {
    if (sizes[i] > size) {
      size = sizes[i];
    }
  }
  
  // Attempt to allocate that size
  block->ptr = malloc(size);
  block->size = (block->ptr == NULL) ? 0 : size;
  
  if (block->ptr == NULL) {
    APP_LOG(APP_LOG_LEVEL_ERROR, "Placement block alloc failed '%s' %d bytes", name, size);    
  }
}

void destroy_shared_placement_block(placement_block_t* block) {
  if (block->ptr != NULL) {
      free(block->ptr);
      block->ptr = NULL;
      block->size = 0;
  }
}
