#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

#define LEN 256

int main() {

    int fd = open("shared.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd == -1) {
        perror("open");
        return -1;
    }

    pid_t pid = fork();

    char buffer[LEN];

    if(pid < 0) {
        perror("fork()");
    }
    else if(pid == 0) {
        snprintf(buffer, LEN, "%d", getpid());
        write(fd, buffer, strlen(buffer));
        write(fd, "\n", 1);
    }
    else {
        snprintf(buffer, LEN, "%d", getpid());
        write(fd, buffer, strlen(buffer));
        write(fd, "\n", 1);
        wait(NULL);

        close(fd);

        fd = open("shared.txt", O_RDONLY);

        char out[LEN];
        ssize_t r = read(fd, out, sizeof(out));
        write(STDOUT_FILENO, out, r);
        
        close(fd);
    }

    return 0;
}

