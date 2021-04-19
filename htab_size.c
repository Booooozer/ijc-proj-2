/*
 * Řešení IJC-DU2
 * Autor: Tomáš Matuš, FIT VUT Brno
 * Login: xmatus37
 * Datum: 19.4.2021
 * Přeloženo: gcc 10.2.0
 */

#include "htab.h"
#include "htab_struct.h"

size_t htab_size(const htab_t * t) {
    return t->size;
}
