#ifndef MEMORY_H
#define MEMORY_H

#include <common.h>

typedef struct _memory_range_t {
	uint32_t base;
	uint32_t size;
} memory_range_t;

typedef struct _memory_region_t {
	uint32_t base;
	uint32_t pos;
	bool down;
} memory_region_t;

#define add_ptr2(x, y) \
	((uintptr_t)((uintptr_t)x + (uintptr_t)y))

#define add_ptr3(x, y, z) \
	((uintptr_t)((uintptr_t)x + (uintptr_t)y + (uintptr_t)z))

#define align_down(p, s) \
	((uintptr_t)(p)&~(s-1))

#define align_up(p, s) \
	align_down((uintptr_t)(p)+s-1, s)

#define ZERO_RANGE(r) \
	memset(&r.base, 0, r.size)

#define RANGE_IS_NULL(r) \
	((r.base == 0) && (r.size == 0))

extern uint32_t get_memory_base(void);

extern uint32_t total_memory_size(void);

extern void memory_region_save(memory_region_t* src, memory_region_t* dest);

extern void memory_region_restore(memory_region_t* dest, memory_region_t* src);

extern void* memory_reserve(memory_region_t* region, uint32_t size, uint32_t align_boundary);

#endif /* !MEMORY_H */
