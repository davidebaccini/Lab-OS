#include <pthread.h>
#include <stdio.h>

void *fn(void *arg) {
    printf("Thread");
}

int main() {

    pthread_t tid;
    pthread_attr_t attr;
    void *retval;

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, fn, NULL);

    pthread_join(tid, &retval);

    return 0;
}