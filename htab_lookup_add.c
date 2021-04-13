//
// Created by tom on 4/13/21.
//

#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key) {
    htab_pair_t *itm = htab_find(t, key);
    if (itm != NULL) {
        itm->value++;
        return itm;
    }

    // init new item
}
