#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n;

void *fn(void *arg) {
    int *i = (int *) arg;
    printf("Thread %d of %d reporting for duty!\n", i, n);
}

int main(int argc, char *argv[]) {
    char *NUM_THREADS = getenv("NUM_THREADS");
    

    if(NUM_THREADS == NULL) {
        n = 2;
    }
    else {
        n = atoi(NUM_THREADS);
    }

    pthread_t tid[n];
    void *retval;

    for(int i = 0; i < n; i++) {
        pthread_create(&tid[i], NULL, fn, (void *) i);
        pthread_join(tid[i], NULL);
    }

    return 0;
}