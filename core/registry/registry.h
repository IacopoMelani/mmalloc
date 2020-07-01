#pragma once

#include <stddef.h>

#include "../types/types.h"

struct RegistryAlloc;

extern void registry_clear_alloc(void *mem_alloc_ptr);

extern unsigned int registry_len();

extern void registry_print_alloc(void);

extern bool registry_write_alloc(size_t size, void *mem_alloc_ptr, const char *context);
