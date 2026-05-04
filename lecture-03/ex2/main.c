#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

struct sigaction act;

int flag = 0;
time_t t1, t2, delta;

void handler(int signum) {
    printf(" Caught %ld\n", signum);

    time_t t2 = time(NULL);

    if(flag == 0) {
        delta = t2 - t1;
        flag = !flag;
    }
    printf("delta: %d", delta);
}

int main() {
    t1 = time(NULL);
    printf("Time: %ld", t1);
    fflush(stdout);

    act.sa_handler = handler;

    sigaction(SIGINT, &act, NULL);

    while(1) {
        sleep(1);
    }

    return 0;
}