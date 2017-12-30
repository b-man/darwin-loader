
#ifndef _LOADER_H
#define _LOADER_H

#include <common.h>
#include <memory.h>

typedef enum {
        LOADER_SUCCESS = 0x0,
        LOADER_BADMAGIC = 0x2,
        LOADER_MALFORMED = 0x3,
        LOADER_BADFILETYPE = 0x4,
        LOADER_EXEC_UNSUPPORTED = 0x5,
        LOADER_EXEC_UNEXPECTED_SEG = 0x6,
        LOADER_EXEC_NONCONTIGIOUS = 0x7,
        LOADER_OBJECT_BADSEGMENT = 0x8,
        LOADER_SYMBOL_NOT_FOUND = 0x9,
        LOADER_OUTOFBOUNDS = 0x10,
        LOADER_NOSYMTAB = 0x11,
        LOADER_BADRELOC = 0x12
} loader_return_t;

#define NAME_LEN 64

typedef struct _loaded_driver_image_t {
	memory_range_t range;
	uint32_t info_offset;
	struct _loaded_driver_image_t* next;
	bool has_exec;
	char name[NAME_LEN];
} loaded_driver_image_t;

#define DRIVER_PAD_START 256

/* All of these are physical */
extern loaded_driver_image_t* gLoadedDriverImages;
extern memory_range_t gKernelMemoryRange;
extern memory_range_t gRAMDiskRange;
extern uint32_t gKernelEntryPoint;
extern uint32_t gKernelMemoryTop;

extern uint32_t gKernelVirtualBase;
extern uint32_t gKernelPhysicalBase;

extern bool gHasDeviceTree;

extern void teardown_loaded_driver_images(void);

#endif
