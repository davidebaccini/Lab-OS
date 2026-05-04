#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc == 1) {
        perror("Too few arguments!\n");
        return -1;
    }

    int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);

    return 0;
}