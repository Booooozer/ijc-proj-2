//
// Created by tom on 4/12/21.
//

#include "htab.h"
#include "htab_struct.h"

size_t htab_bucket_count(const htab_t * t) {
    return t->arr_size;
}
