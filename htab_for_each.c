//
// Created by tom on 4/14/21.
//

#include "htab.h"
#include "htab_struct.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)) {
    // loop through indexes
    for (size_t i = 0; i < t->arr_size; i++) {
        struct htab_item *itm = t->arr[i];
        // empty index
        if (itm == NULL) {
               continue;
        }

        // loop through linked list
        do {
            f(&itm->pair);
            itm = itm->next;
        } while (itm != NULL);
    }
}
