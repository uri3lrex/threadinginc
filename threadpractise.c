#include <pthread.h>
#include <stdio.h>

void* thread_function(void* arg) {
    printf("Thread is running and thread works perfectly!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    int result = pthread_create(&thread, NULL, thread_function, NULL);

    if (result) {
        printf("Error creating thread\n");
        return 1;
    }

    pthread_join(thread, NULL);
    printf("Thread finished\n");
    return 0;
}
