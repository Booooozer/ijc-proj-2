//
// Created by tom on 4/12/21.
//

#include "htab.h"
#include "htab_struct.h"

//#ifdef MOVETEST

htab_t *htab_move(size_t n, htab_t *from) {
    htab_t *to = htab_init(n);
    if (to == NULL) {
        return NULL;
    }

    to->arr_size = from->arr_size;
    to->size = from->size;

    // recalculate indexes of item and store them in new table
    struct htab_item *itemMove;
    size_t newIndex;
    for (size_t i = 0; i < from->arr_size; i++) {
        while (from->arr[i] != NULL) {
            // take first item from linked list
            itemMove = from->arr[i];
            from->arr[i] = itemMove->next;

            // get new index and move item to the new hash table
            newIndex = htab_hash_function(itemMove->pair.key) % to->arr_size;
            itemMove->next = to->arr[newIndex];
            to->arr[newIndex] = itemMove;
        }


    }

    return to;
}

//#endif
