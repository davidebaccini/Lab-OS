#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

const int N = 3;

int main() {

    int fd[N];
    char name[N] = {'a', 'b', 'c'};

    for(int i = 0; i < 3; i++) {
        char *file_name = strncat(name[i], ".txt", 20);
        fd[i] = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    }

    for(int i = 0; i < 3; i++) {
        printf("FD: %d", fd[i]);
    }

    int fd_d = open("d.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    for(int i = 0; i < 3; i++) {
        close(fd[i]);
    }
    close(fd_d);

    return 0;
}