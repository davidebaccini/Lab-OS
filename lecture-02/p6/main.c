#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();

	if(pid < 0) {
		printf("Fork failed");
		return 1;
	}
	else if(pid == 0) {
		sleep(5);
		printf("I am the child, my PID is %d, my parent's PID is %d\n", getpid(), getppid());
		return 0;
	}
	else {
		//wait(NULL);
		printf("I am the parent process, my PID is %d, my child's PID is %d\n", getpid(), pid);
		return 0;
	}
}
