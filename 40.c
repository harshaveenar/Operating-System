#include <stdio.h>
#include <sys/stat.h>
#include <io.h>

int main() {
    const char *filename = "hello.txt";
    mode_t new_permissions = _S_IREAD | _S_IWRITE; // rw-rw-rw-

    if (_chmod(filename, new_permissions) == 0) {
        printf("File permissions changed successfully.\n");
        struct _stat file_info;
        if (_stat(filename, &file_info) == 0) {
            printf("Updated permissions: %o\n", file_info.st_mode & 07777);
        } else {
            perror("_stat");
        }
    } else {
        perror("_chmod");
    }

    return 0;
}

