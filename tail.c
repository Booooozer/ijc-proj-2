#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 511

/* parser for -n NUM parameter
 * returns number of lines to be printed / from what line to print
 * when '+' is specified
 * returns true in a pointer to bool when '+' is specified
 */
long int parseN(char *argv[], bool *plus) {
    long int lines = 0;
    char *left;
    if (strcmp(argv[1], "-n") == 0) {
        if (strstr(argv[2], "+") != NULL) {
            // '+' found
            *plus = true;
        } else {
            // '+' not found
            *plus = false;
        }
        lines = strtol(argv[2], &left, 10);
        printf("%s\n", left);
        if (strcmp(left, "") != 0) {
            lines = -1;
        }
    } else {
        lines = -1;
    }

    return lines;
}

void printTail(FILE *fp, long int lines) {
    /*
     * allocate lines*511 array
     * cycle through it with fgets and print last 'lines' at the end
     * somehow check for lines that are longer than 511
     */

    char line[MAX_LINE];
    while(fgets(line, MAX_LINE, fp) != NULL) {
        printf("%s", line);
    }
}

int main(int argc, char* argv[]) {

    if (argc > 4) {
        fprintf(stderr, "Too many arguments\n");
        return 1;
    }

    long int lines = 10;
    bool plus = false;
    char *left = NULL;
    FILE *fp = stdin;

    switch (argc) {
        case 1:
            // last 10 from stdin
            printTail(fp, lines);
            break;

        case 2:
            // last 10 from file
            fp = fopen(argv[argc - 1], "r");
            if (fp == NULL) {
                fprintf(stderr, "Failed to open file %s", argv[argc - 1]);
            }
            printTail(fp, lines);
            break;

        case 3:
            // n specified + stdin
            lines = parseN(argv, &plus);
            if (lines < 0) {
                fprintf(stderr, "Invalid parameters\n");
                return 1;
            }
            printTail(fp, lines);
            break;

        case 4:
            // n specified + file
            fp = fopen(argv[argc - 1], "r");
            if (fp == NULL) {
                fprintf(stderr, "Failed to open file %s", argv[argc - 1]);
            }
            lines = parseN(argv, &plus);
            if (lines < 0) {
                fprintf(stderr, "Invalid parameters\n");
                return 1;
            }
            printTail(fp, lines);
            break;

        default:
            fprintf(stderr, "Too many parameters\n");
            return 1;
    }

    return 0;
}
