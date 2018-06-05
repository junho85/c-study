#include <stdio.h>
#include <string.h>

void test_strstr() {
    char str[] = "I'm Joon Kim.";
    char *pch;
    pch = strstr(str, "Joon");
    puts(pch); // Joon Kim.

    strncpy(pch, "June", 4); // replace Joon to June
    puts(str);
}

int main() {
    test_strstr();

    return 0;
}