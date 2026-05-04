#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *msg = "Hello, file descriptor!\n";
    int fd_write = open("hello.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    printf("Attempting to opern FD: %d...\n", fd_write);
    if(fd_write == -1) {
        perror("The write has failed!\n");
        return 1;
    }

    if(write(fd_write, msg, strlen(msg)) == -1) {
        perror("write");
        close(fd_write);
        return -1;
    }

    return 0;
}