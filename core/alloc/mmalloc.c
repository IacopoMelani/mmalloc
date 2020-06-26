#include "mmalloc.h"

#include <stddef.h>
#include <malloc.h>

void mfree(void *ptr, unused const char *context)
{
    free(ptr);
    printf("-- Deallocated context '%s'\n", context);
}

void *mcalloc(size_t nItems, size_t size, unused const char *context)
{
    void *p = calloc(nItems, size);

    printf("++ Allocated with calloc context '%s' with %ld elements by size %ld\n", context, nItems, size);
    return p;
}

void *mmalloc(size_t size, unused const char *context)
{
    void *p = malloc(size);

    printf("++ Allocated context '%s' for size %ld\n", context, size);
    return p;
}

void *mrealloc(void *ptr, size_t size, unused const char *context)
{
    if (size == 0)
    {
        printf("-- Realloc context '%s' with size 0, call free\n", context);
        mfree(ptr, context);
        return NULL;
    }

    ptr = realloc(ptr, size);

    printf("++ Reallocated context '%s' with new size %ld\n", context, size);
    return ptr;
}
