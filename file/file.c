#include <stdio.h>
#include <libgen.h>

int main() {
    // suppose current file is /Users/junho85/CLionProjects/study-c/file.c
    printf("__FILE__ %s\n", __FILE__); // /Users/junho85/CLionProjects/study-c/file.c
    printf("dirname %s\n", dirname(__FILE__)); // /Users/junho85/CLionProjects/study-c
    printf("basename %s\n", basename(__FILE__)); // file.c

    return 0;
}