#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_write(char *path) {
    struct stat s;
    int out = stat(path, &s)
    if (out != 0) {
        perror(path);
        exit(1);
    }

    mode_t new_mode = s.st_mode;
    if (!(new_mode & S_IWOTH)) {                // mode: 0b111, flag: 0b100
        printf("%s is not publically writable\n", path);
        return;
    }

    printf("removing public write from %s\n", path); // ~flag: 0b011, mode: 0b111
    mode_t new_mode = new_mode & ~S_IWOTH;

    if (chmod(path, new_mode) != 0) {
        perror(pathname);
        exit(1);
    }

}

int main (int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        chmod_write(argv(i));
    }
    return 0;
}