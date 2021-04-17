//
// Created by tom on 4/12/21.
//

#include <stdlib.h>
#include <stdint.h>
#include "htab.h"

#ifndef HASHTEST

size_t htab_hash_function(const char *str) {
    uint32_t h=0;     // musí mít 32 bitů
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}

#endif
