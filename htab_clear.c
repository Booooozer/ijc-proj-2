/*
 * Řešení IJC-DU2
 * Autor: Tomáš Matuš, FIT VUT Brno
 * Login: xmatus37
 * Datum: 19.4.2021
 * Přeloženo: gcc 10.2.0
 */

#include "htab.h"
#include "htab_struct.h"

void htab_clear(htab_t * t) {
    for (size_t i = 0; i < t->arr_size; i++) {
        while (t->arr[i] != NULL) {
            htab_erase(t, t->arr[i]->pair.key);
        }
    }
}
