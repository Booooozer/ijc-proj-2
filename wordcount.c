//
// Created by tom on 4/14/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "io.h"

#define WORD_MAX 128

void printHash(htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main(int argc, char *argv[]) {
    // TODO open file, warning checking
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

    htab_t *t = htab_init(20);

    while (read_word(word, WORD_MAX, fp) != EOF) {
        htab_lookup_add(t, word);
    }

    htab_for_each(t, printHash);

    htab_free(t);

    fclose(fp);

    return 0;
}
