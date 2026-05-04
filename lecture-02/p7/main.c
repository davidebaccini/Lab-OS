#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	//int p = atoi(argv[1]);
	//int d = atoi(argv[2]);
	int p = 5;
	int d = 4;

	if((p < 0) || (p < d)) {
		printf("Error in p value!\n");
		return 1;		
	}

	if((d < 0) || (d > 10)) {
		printf("Error in d value!\n");
		return 1;
	}
	printf("All ok, program keeps going\n");
	
	// fare un tree di processes
	// p = 4 e d = 3, 3 layers with 4 nodes each
	
	pid_t pid[4];

	for(int i = 0; i < p; i++) {
		pid[i] = fork();
		if(pid[i] < 0) {
			printf("Error in PID!\n");
			return 1;
		}
		else if(pid[i] == 0) {
			printf("Child %d, from Parent: \n", i, getppid());
		}
		else {
			printf("Parent %d\n", i);
		}
	}
	return 0;
}
