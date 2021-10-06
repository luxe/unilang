// zebra
// =====

// Add zebra lines from stdin to stdout 


// Usage
// -----

// $ zebra < file

// $ ps aux | zebra | less -S

// $ ps aux | zebra --light | less -S

// $ ps aux | zebra --color 128 | less -S


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define streq(a,b) strcmp(a,b) == 0
#define RESET printf("\x1B[0m")
#define DARK "8m"
#define LIGHT "254m"
#define BASE "\x1B[48;5;"

void usage()
{
    printf("usage: zebra [OPTION] < file\n\n");
    printf("OPTION\n\n");
    printf("     --light        set light background\n");
    printf("     --color 128    set any background color\n\n");
    exit(1);
}

int main(int argc, const char* argv[])
{
    int c;
    int alt = 0;
    int light = 0;
    char bgcol[32] = {0};

    if (argc >= 2 && streq(argv[1], "--help")) {
        usage();
    }
    else if (argc >= 2 && streq(argv[1], "--light")) {
        light = 1;
    }
    else if (argc >= 3 && streq(argv[1], "--color")) {
        snprintf(bgcol, sizeof(bgcol), BASE "%sm", argv[2]);
    }

    if (bgcol[0] == 0) {
        if (light)
            strcpy(bgcol, BASE LIGHT);
        else
            strcpy(bgcol, BASE DARK);
    }

    // TODO: files
    FILE *stream = stdin;

    while (1) {
        c = getc(stream);

        if (c == EOF)
            break;

        putc(c, stdout);

        if (c == '\n') {
            alt ^= 1;
            if (alt) {
                printf("%s", bgcol);
            }
            else {
                RESET;
            }
        }
    }

    RESET;
}
