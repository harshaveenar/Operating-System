#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *directory;
    struct dirent *entry;

    char path[100];

    // Get the directory path from the user
    printf("Enter the directory path: ");
    scanf("%s", path);

    // Open the directory
    directory = opendir(path);

    // Check if the directory was opened successfully
    if (directory == NULL) {
        printf("Error opening the directory.\n");
        return 1; // Exit the program with an error code
    }

    // List files and directories in the given path
    printf("\nFiles and Directories in %s:\n", path);
    while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(directory);

    return 0; // Exit the program successfully
}

