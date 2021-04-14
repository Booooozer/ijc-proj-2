//
// Created by tom on 4/13/21.
//

#include "htab.h"
#include "htab_struct.h"

void htab_clear(htab_t * t) {
    for (size_t i = 0; i < t->arr_size; i++) {
        while (t->arr[i] != NULL) {
            htab_erase(t, t->arr[i]->pair.key);
        }
    }
}
