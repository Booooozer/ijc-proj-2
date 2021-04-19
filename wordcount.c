//
// Created by tom on 4/14/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "htab.h"
#include "io.h"

/*
 * Dle doporučení, na která jsem narazil, je vhodné zvolit velikost tabulky tak,
 * aby docházelo k vytížení cca 70 - 75% pro omezení počtu kolizí. Dále je vhodné zvolit
 * prvočíslo, díky čemu se nebudou násobky jednoho čísla ukládat na stejný index.
 * Velikost volím ze statistiky průměrného počtu unikátních slov v 7 dlouhých knihách.
 */
#define HASH_TAB_SIZE 12143

#define WORD_MAX 128

#ifdef HASHTEST
// different hash function
size_t htab_hash_function(const char *str) {
    uint32_t h = 5381;
    int c;
    printf("asdfasdf\n");
    while ((c = (*str++))) {
        h = ((h << 5) + h) + c;
    }

    return h;
}
#endif

void printHash(htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main(int argc, char *argv[]) {
    int err = 1;    // word overflow warning

    if (argc > 2) {
        fprintf(stderr, "Too many parameters\n");
        return 1;
    }

    FILE *fp;
    if (argc == 2) {
        fp = fopen(argv[argc - 1], "r");
    } else {
        fp = stdin;
    }
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file\n");
    }

    char word[WORD_MAX];

    htab_t *t = htab_init(HASH_TAB_SIZE);
    int wordLen;
    while ( (wordLen = read_word(word, WORD_MAX, fp)) != EOF) {
        if (wordLen > WORD_MAX && err == 1) {
            fprintf(stderr, "Word overflow detected\n");
            err = 0;
        }
        htab_lookup_add(t, word);
    }

    htab_for_each(t, printHash);

    #ifdef MOVETEST
    printf("\n==================================================\n\n");

    htab_t *t2 = htab_move(32443, t);
    htab_for_each(t2, printHash);

    htab_free(t2);
    #endif

    htab_free(t);
    fclose(fp);

    return 0;
}
