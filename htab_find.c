/*
 * Řešení IJC-DU2
 * Autor: Tomáš Matuš, FIT VUT Brno
 * Login: xmatus37
 * Datum: 19.4.2021
 * Přeloženo: gcc 10.2.0
 */

#include <string.h>
#include "htab.h"
#include "htab_struct.h"

htab_pair_t * htab_find(htab_t * t, htab_key_t key) {
    size_t index = htab_hash_function(key) % t->arr_size;

    struct htab_item *itm = t->arr[index];
    // empty index
    if (itm == NULL) {
        return NULL;
    }

    // compare keys with first item on index
    if (strcmp(itm->pair.key, key) == 0) {
        // keys match
        return &itm->pair;
    } else {
        // run through linked list and search for key
        for (; itm->next != NULL; itm = itm->next) {
            // compare keys
            if (strcmp(itm->pair.key, key) == 0) {
                // key in list matches
                return &itm->pair;
            }
        }
    }

    // key not found
    return NULL;
}
