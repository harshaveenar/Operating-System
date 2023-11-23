#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void grep(char *file_name, char *pattern) {
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Could not open the file %s\n", file_name);
        return;
    }

    char line[1024];
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;

        if (strstr(line, pattern) != NULL) {
            printf("%s: Line %d: %s", file_name, line_number, line);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <pattern> <file1> [<file2> ...]\n", argv[0]);
        return 1;
    }

    char *pattern = argv[1];

    for (int i = 2; i < argc; i++) {
        char *file_name = argv[i];
        grep(file_name, pattern);
    }

    return 0;
}

