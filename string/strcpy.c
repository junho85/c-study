#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dst, const char *src) {
    int i = 0;
    while (*(src + i)) {
        *(dst + i) = *(src + i);
        i++;
    }
    return dst;
}

char *my_strcpy2(char *dst, const char *src) {
    char* temp = dst;
    while ((*(temp++) = *(src++)));
    return dst;
}

int main() {
    char *src = "hello world";
    char dst1[20];
    char dst2[20];
    char dst3[20];

    char *dst10 = strcpy(dst1, src);
    printf("%s\n", dst1);
    printf("%s\n", dst10);

    char *dst20 = my_strcpy(dst2, src);
    printf("%s\n", dst2);
    printf("%s\n", dst20);

    char *dst30 = my_strcpy2(dst3, src);
    printf("%s\n", dst3);
    printf("%s\n", dst30);

    return 0;
}