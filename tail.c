#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 512

/*
 * parser for -n NUM parameter
 * returns number of lines to be printed / from what line to print
 * returns true in a pointer to bool when '+' is specified
 */
long int parseN(char *argv[], bool *plus) {
    long int lines = 10;
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
        if (strcmp(left, "") != 0 || lines == 0) {
            lines = -1;
        }
    } else {
        lines = -1;
    }

    return lines;
}

// removes leftover when currently read line exceeds length MAX_LINE
void removeLeftoverLine(FILE *fp) {
    char lineThrow[MAX_LINE];
    do {
        fgets(lineThrow, MAX_LINE, fp);
    } while (strstr(lineThrow, "\n") == NULL);
}

// prints specified number of lines from the end of file
void printTail(FILE *fp, long int lines) {
    char lineArr[lines][MAX_LINE];
    bool printErr = true;
    unsigned long count = 0;

    // cycles through array and stores newly red lines
    while (fgets(lineArr[count % lines], MAX_LINE, fp) != NULL){
        if (strstr(lineArr[count % lines], "\n") == NULL) {
            //lineArr[count % lines][MAX_LINE - 2] = '\n';
            removeLeftoverLine(fp);
            if (printErr == true) {
                printErr = false;
                fprintf(stderr,"Line overflow detected\n");
            }
        }
        count++;
    }

    // prints out last lines in the same order as they were saved in file
    for (int i = 0; i < lines; i++) {
        if (strstr(lineArr[count % lines], "\n") == NULL) {
            printf("%s\n", lineArr[(count + i) % lines]);
        } else {
            printf("%s", lineArr[(count + i) % lines]);
        }
    }
}

// prints all lines from specified line
void printPlusTail(FILE *fp, long int lines) {
    bool printErr = true;
    char line[MAX_LINE];
    long int count = 0;
    while(fgets(line, MAX_LINE, fp) != NULL) {
        count++;
        if (count < lines)
            continue;

        if (strstr(line, "\n") != NULL) {
            printf("%s", line);
        } else {
            removeLeftoverLine(fp);
            printf("%s\n", line);
            if (printErr == true) {
                printErr = false;
                fprintf(stderr,"Line overflow detected\n");
            }
        }
    }
}

int main(int argc, char* argv[]) {
    long int lines = 10;
    bool plus = false;
    //char *left = NULL;
    FILE *fp = stdin;

    switch (argc) {
        case 1:
            // last 10 from stdin
            break;

        case 2:
            // last 10 from a file
            fp = fopen(argv[argc - 1], "r");
            if (fp == NULL) {
                fprintf(stderr, "Failed to open file %s\n", argv[argc - 1]);
            }
            break;

        case 3:
            // n specified + stdin
            lines = parseN(argv, &plus);
            if (lines < 0) {
                fprintf(stderr, "Invalid parameters\n");
                return 1;
            }
            break;

        case 4:
            // n specified + file
            fp = fopen(argv[argc - 1], "r");
            if (fp == NULL) {
                fprintf(stderr, "Failed to open file %s\n", argv[argc - 1]);
            }
            lines = parseN(argv, &plus);
            if (lines < 0) {
                fprintf(stderr, "Invalid parameters\n");
                return 1;
            }
            break;

        default:
            fprintf(stderr, "Too many parameters\n");
            return 1;
    }

    if (plus == true) {
        printPlusTail(fp, lines);
    } else if (plus == false) {
        printTail(fp, lines);
    }

    return 0;
}
