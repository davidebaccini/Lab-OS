#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

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
    else if(pid == 0) {
        
    }