#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 6

void* printhello(void* threadid) {
    int tid = (int)(intptr_t)threadid;  // Properly cast the pointer back to an int
    printf("\n%d: Hello World!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int t; //counting for the loop
    int res; //the actual statement?
    for (t=0; t<NUM_THREADS;t++){
        printf("Creating thread %d\n",t);
        res = pthread_create(&threads[t], NULL, printhello, (void *)(intptr_t)t); //pthread_create directly makes the  thread
    //syntax: the variable= pthread_create(&thread, NULL (attribute),thread_function,NULL (pointer))
    if (res) {
        printf("Error creating thread\n");
        exit (-1);
    }

    pthread_join(threads[t],NULL);
    }
   /** OUT OF ORDER??  for (t=0;t<NUM_THREADS;t++){
    pthread_join(threads[t], NULL);
    }*/ 
    printf("Thread finished\n");
    return 0;
}
