#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];

    if(pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if(pid < 0) {
        perror("fork");
        return 1;
    }
    else if(pid == 0) {     // child is writing
        close(fd[0]);
        const char *msg = "The answer is 42\n";
        ssize_t w = write(fd[1], msg, strlen(msg));
        close(fd[1]);
        exit(0);
    }
    
    close(fd[1]);
    char buf[256];
    ssize_t n = read(fd[0], buf, sizeof(buf));

    while(n > 0) {
        write(STDOUT_FILENO, buf, n);
        close(fd[0]);
        wait(NULL);
        return 0;
    }

    return 0;
}