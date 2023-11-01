// Print lines containing  specified substring from the files specified as arguments

#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE 65536

void search_stream(FILE *stream, char stream_name[], char search_for[]);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "usage: %s <substring> [files]\n", argv[0]);
    }

    if (argc == 2) {
        search_stream(stdin, "<stdin>", argv[1]);
    } else {
        for (int arg = 2; arg < argc; arg++) {
            FILE *f = fopen(argv[arg], "r");
            if (f == NULL) {
                fprintf(stderr, "%s: %s: %s", argv[0], argv[arg], strerror(errno));
                return 1;
            }
            search_stream(f, argv[arg], argv[1]);
            fclose(f);
        }
    }
    return 0;
}

// Searches for a substring in a file stream.
void search_stream(FILE *stream, char stream_name[], char search_for[]) {
    char line[MAX_LINE];
    int line_num = 1;

    while (fgets(line, MAX_LINE, stream) != NULL) {
        if (strstr(line, search_for) != NULL) {
            printf("%s: %d: %s", stream_name, line_num, line);
        }
        line_num++;
    }
}