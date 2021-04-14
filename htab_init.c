//
// Created by tom on 4/12/21.
//

#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

htab_t *htab_init(size_t n) {
    htab_t *table = malloc(sizeof(htab_t) + n * sizeof(struct htab_item *));
    if (table == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < n; i++) {
        table->arr[i] = NULL;
    }
    table->size = 0;
    table->arr_size = n;
    return table;
}
