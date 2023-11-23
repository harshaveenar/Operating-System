#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char content[1000];
    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; 
    }
    printf("Enter content to write to the file:\n");
    scanf(" %[^\n]", content);
    fprintf(file, "%s", content);
    fclose(file);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return 1; 
    }
    printf("\nContent of the file:\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);

    return 0; 
}

