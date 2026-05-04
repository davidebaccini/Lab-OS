#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

#define PIPE_NUMBERS 2

int main(void) {
    srand(time(NULL));

    int fd[PIPE_NUMBERS][2];

    for(int i = 0; i < PIPE_NUMBERS; i++) {
        if(pipe(fd[i]) == -1) {
            perror("pipe");
            return 1;
        }
    }

    pid_t pid = fork();

    if(pid < -1) {
        perror("fork");
        return 1;
    }
    else if(pid == 0) {
        close(fd[0][0]);
        close(fd[1][1]);
        char buffer[256] = " ";

        ssize_t r = read(fd[1][0], buffer, strlen(buffer));
        close(fd[1][0]);

        int num = atoi(buffer);
        num = num * 2;
        sprintf(buffer, "%d\n", num);

        ssize_t w = write(fd[0][1], buffer, strlen(buffer));
        close(fd[0][1]);

        exit(0);
    }

    close(fd[1][0]);
    close(fd[0][1]);

    int num = rand() % 9 + 1;
    printf("Rand: %d\n", num);
    char buffer[256];
    sprintf(buffer, "%d\n", num);
    ssize_t w = write(fd[1][1], buffer, strlen(buffer));
    close(fd[1][1]);

    ssize_t n = read(fd[0][0], buffer, strlen(buffer));
    while(n > 0) {
        write(STDOUT_FILENO, buffer, n);
        close(fd[0][0]);
        wait(NULL);
        return 0;
    }

    return 0;
}