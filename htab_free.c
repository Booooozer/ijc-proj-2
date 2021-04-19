/*
 * Řešení IJC-DU2
 * Autor: Tomáš Matuš, FIT VUT Brno
 * Login: xmatus37
 * Datum: 19.4.2021
 * Přeloženo: gcc 10.2.0
 */

#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

void htab_free(htab_t * t) {
    htab_clear(t);
    free(t);
}
