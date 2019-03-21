#include <stdio.h>
#include <unistd.h> // getcwd
#include <limits.h> // PATH_MAX

int main() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        return -1;
    }

    printf("cwd %s\n", cwd);

    return 0;
}