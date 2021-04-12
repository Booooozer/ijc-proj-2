//
// Created by tom on 4/11/21.
//

#ifndef HTAB_STRUCT_H
#define HTAB_STRUCT_H

#include "htab.h"

struct htab_item {
    struct htab_pair pair;
    struct htab_item *next;
};

struct htab {
    size_t size;            // aktuální počet záznamů [(key,data),next]
    size_t arr_size;        // velikost následujícího pole ukazatelů
    struct htab_item *arr[];     // pole ukazatelů na prvky tabulky
};

#endif // HTAB_STRUCT_H
