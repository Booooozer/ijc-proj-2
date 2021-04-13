//
// Created by tom on 4/13/21.
//

#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

void htab_free(htab_t * t) {
    htab_clear(t);
    free(t);
}
