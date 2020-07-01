#include "mmalloc.h"

#include <stddef.h>
#include <malloc.h>

#include "../registry/registry.h"

void mfree(void *ptr, unused const char *context)
{
    void *tmpPtr;

    tmpPtr = ptr;

    free(ptr);

    registry_clear_alloc(tmpPtr);

    printf("-- Deallocated context '%s'\n", context);
}

void *mcalloc(size_t nItems, size_t size, unused const char *context)
{

    void *p = calloc(nItems, size);

    registry_write_alloc(size, p, context);

    printf("++ Allocated with calloc context '%s' with %ld elements by size %ld\n", context, nItems, size);
    return p;
}

void *mmalloc(size_t size, unused const char *context)
{
    void *p = malloc(size);

    registry_write_alloc(size, p, context);

    printf("++ Allocated context '%s' for size %ld\n", context, size);
    return p;
}

void *mrealloc(void *ptr, size_t size, unused const char *context)
{
    void *tmpPtr;

    tmpPtr = ptr;

    if (size == 0)
    {
        printf("-- Realloc context '%s' with size 0, call free\n", context);
        mfree(ptr, context);

        return NULL;
    }

    ptr = realloc(ptr, size);

    registry_clear_alloc(tmpPtr);
    registry_write_alloc(size, ptr, context);

    printf("++ Reallocated context '%s' with new size %ld\n", context, size);
    return ptr;
}
