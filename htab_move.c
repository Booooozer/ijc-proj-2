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

    // recalculate indexes of item and store them in new table

    return to;
}

//#endif
