//
// Created by tom on 4/13/21.
//

#include <stdlib.h>
#include <string.h>
#include "htab.h"
#include "htab_struct.h"

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key) {
    htab_pair_t *itm = htab_find(t, key);
    if (itm != NULL) {
        itm->value++;
        return itm;
    }

    // init new item
    struct htab_item *newItm = malloc(sizeof(struct htab_item));
    if (newItm == NULL) {
        return NULL;
    }
    // allocate length of key + \0 because strlen() excludes that
    size_t keySize = strlen(key) + 1;
    newItm->pair.key = malloc(keySize);
    memcpy((char*)newItm->pair.key, key, keySize);
    //newItm->next = NULL;
    newItm->pair.value = 1;

    // calculate index of new key
    size_t index = htab_hash_function(key) % t->arr_size;
    // store new item to the front of linked list
    newItm->next = t->arr[index];
    t->arr[index] = newItm;

    return &newItm->pair;
}
