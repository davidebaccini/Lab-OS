#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fn(void *arg) {
    pthread_t tid = (pthread_t) arg;
    printf("I am thread: %lu", tid);
    void *ret = tid * tid;
    pthread_exit((void *) ret);
}

int main(int argc, char *argv[]) {
    int n;

    if(argc > 1) {
        n = atoi(argv[1]);
    }
    else {
        n = 4;
    }

    pthread_t tid;
    void *retval;

    for(int i = 0; i < n; i++) {
        pthread_create(&tid, NULL, fn, (void *) i);
        pthread_join(tid, &retval);
        printf("Thread: %d, returned: %u\n", i, (int *) retval);
    }

    return 0;
}