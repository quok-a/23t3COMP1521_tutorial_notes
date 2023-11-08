// print the contents of $HOME/.diary

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *file = ".diary";

int main (int argc, char *argv[]) {
    char *home = getenv("HOME");
    if (home == NULL) {
        home = ".";
    }

    // + 2 null terminator, adding a `/` between the two paths
    int path_len = strlen(home) + strlen(file) + 2;
    char *diary_path = malloc(path_len);

    snprintf(diary_path, path_len, "%s/%s", home, file);

    FILE *f = fopen(diary_path, "r");
    if (f == NULL) {
        perror(diary_path);
        return 1;
    }

    char read;
    while ((read = fgetc(f)) != EOF) {
        fputc(read, stdout);
    }

    fclose(f);
    free(diary_path);

    return 0;
}