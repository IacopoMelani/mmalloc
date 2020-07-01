#include <stdlib.h>
#include <stdio.h>

#include "core/types/types.h"

#include "core/alloc/mmalloc.h"
#include "core/registry/registry.h"

int main()
{
    int *m = mmalloc(sizeof(int), "int");
    mfree(m, "int");

    int *c = mcalloc(10, sizeof(int), "10 int");

    c = mrealloc(c, 15, "10 int");

    mfree(c, "10 int");

    int *z = mmalloc(sizeof(int), "zero int");

    z = mrealloc(z, 0, "zero int");

    registry_cap();

    return 0;
}