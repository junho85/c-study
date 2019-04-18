#include <stdio.h>
#include <stdlib.h> // exit
#include <unistd.h> // getopt

int main(int argc, char *argv[]) {
    printf("-- getopt example\n");

    int opt;
    while ((opt = getopt(argc, argv, "lf:")) != -1) {
        switch (opt) {
            case 'l':
                printf("l enabled\n");
                break;
            case 'f':
                printf("filename=%s\n", optarg);
                break;
            default: /* '?' */
                fprintf(stderr, "Usage: %s [-l] [-f filename]\n", argv[0]);
                exit(0);
        }
    }
    return 0;
}

#if 0
$ ./getopt -l -f test.txt

# output
-- getopt example
l enabled
filename=test.txt

#endif
