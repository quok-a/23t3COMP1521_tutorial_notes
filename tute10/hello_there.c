#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>


void *thread_run(void *data) {
    char *string = data;

    while (true) {
        printf("%s", string);
    }
}

int main(void) {
    char *msg = "Hello\n";

    pthread_t thread;
    pthread_create(&thread, NULL, thread_run, msg);

    while (true) {
        printf("there\n");
    }

}