#ifndef MACHO_LOADER_H
#define MACHO_LOADER_H

#include <common.h>

#include <loader.h>
#include <mach-o/macho.h>
#include <mach-o/nlist.h>

typedef uint32_t loader_bias_t;

typedef struct {
	uint8_t *file;
	uint8_t *base;
	char *string_base;
	uint32_t filetype;
	uint32_t entry_point;
	uint32_t vmsize;
	uint32_t vm_bias;
	loader_bias_t loader_bias;
	bool compressed;
	bool is_prelinked;
	struct nlist *symbol_base;
	struct symtab_command *symtab;
	struct segment_command *first_segment;
	struct dysymtab_command *dsymtab;
	struct dyld_info_command *dyld_info;
} mach_loader_context_t;

extern loader_return_t mach_file_init(mach_loader_context_t* file, uint8_t* fbase);

extern loader_return_t mach_file_vmsize(mach_loader_context_t* file, uint32_t* sz);

extern void mach_file_set_vm_bias(mach_loader_context_t* file, uint32_t loader_bias);

extern loader_return_t mach_file_map(mach_loader_context_t* file, uint8_t* load_addr, uint32_t vmsize);

extern loader_return_t mach_file_get_entry_point(mach_loader_context_t* file, uint32_t* entry);

#endif /* !MACHO_LOADER_H */
