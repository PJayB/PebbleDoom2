#pragma once

typedef struct placement_block_s {
    void* ptr;
    size_t size;
} placement_block_t;

#define load_pack(pack, resource_id) _load_pack(#pack, pack, resource_id)
#define load_pack_placement(pack, heap, resource_id) _load_placement_pack(#pack, pack, resource_id, (heap)->ptr, (heap)->size)
#define load_pack_placement_offset(pack, heap, offset, resource_id) _load_placement_pack(#pack, pack, resource_id, ((uint8_t*)(heap)->ptr) + (offset), (heap)->size - (offset))
#define init_shared_placement_block(block, sizes, num_resources) _init_shared_placement_block(#block, block, sizes, num_resources)

void _load_pack(const char* name, prezr_pack_t* pack, uint32_t resource_id);
void _load_pack_placement(const char* name, prezr_pack_t* pack, uint32_t resource_id, void* heap, size_t heap_size);
void unload_pack(prezr_pack_t* pack);
void unload_pack_placement(prezr_pack_t* pack);

size_t get_resource_size(uint32_t resource_id);

void _init_shared_placement_block(const char* name, placement_block_t* block, const size_t* sizes, size_t num_resources);
void destroy_shared_placement_block(placement_block_t* block);

