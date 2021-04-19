/*
 * Řešení IJC-DU2
 * Autor: Tomáš Matuš, FIT VUT Brno
 * Login: xmatus37
 * Datum: 19.4.2021
 * Přeloženo: gcc 10.2.0
 */

#include <stdio.h>
#include <ctype.h>
#include "io.h"
#include "htab.h"

int read_word(char *s, int max, FILE *f) {
    if (f == NULL) {
        fprintf(stderr, "File returns NULL\n");
        return -1;
    }
    int length = 0;
    int c;

    // read extra white-spaces and ignore them
    while ((c = fgetc(f)) != EOF && isspace(c)); // empty body

    if (c == EOF) {
        return EOF;
    }

    s[0] = (char)c;
    length = 1;
    for (; length < max - 1; length++) {
        c = fgetc(f);
        if (isspace(c)) {
            break;
        }
        s[length] = (char)c;
    }
    // add end of string
    s[length] = '\0';

    // too long word
    if (length == max - 1) {
        while (isspace(c = fgetc(f)) == 0) {    // isspace() returns nonzero when c is white-space
            length++;
        }
    }

    return length;
}
