#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

unsigned get_file_size(const char *file_name) {
    struct stat sb;
    if (stat(file_name, &sb) != 0) {
        fprintf(stderr, "'stat' failed for '%s': %s.\n",
                file_name, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return sb.st_size;
}

unsigned get_file_size2(const char *file_name) {
    FILE *f = fopen(file_name, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    fclose(f);
    return fsize;
}

void read_test() {
    char ch, file_name[25];
    FILE *fp;

    printf("Enter name of a file you wish to see\n");
    gets(file_name);

    fp = fopen(file_name, "r"); // read mode

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("The contents of %s file are:\n", file_name);

    while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);

    fclose(fp);
}

int main() {
    printf("filesize=%d\n", get_file_size(__FILE__));
    printf("filesize=%d\n", get_file_size2(__FILE__));

    // suppose current file is /Users/junho85/CLionProjects/study-c/file.c
    printf("__FILE__ %s\n", __FILE__); // /Users/junho85/CLionProjects/study-c/file.c
    printf("dirname %s\n", dirname(__FILE__)); // /Users/junho85/CLionProjects/study-c
    printf("basename %s\n", basename(__FILE__)); // file.c

    return 0;
}