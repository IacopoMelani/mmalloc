#pragma once

#include <stddef.h>

#include "../types/types.h"

struct RegistryAlloc;

extern unsigned int registry_cap();

extern void registry_clear_alloc(void *mem_alloc_ptr);

extern bool registry_write_alloc(size_t size, void *mem_alloc_ptr, const char *context);
