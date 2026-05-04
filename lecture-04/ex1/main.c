#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fn() {
    pthread_t tid = pthread_self();
    printf("Hello from the thread!\n");
    printf("My TID: %u\n", tid);
}

int main() {

    pthread_t tid;
    pthread_attr_t attr;
    void *retval;

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, fn, NULL);

    pthread_join(tid, &retval);
    pthread_exit(tid);

    return 0;
}