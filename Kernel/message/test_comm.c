#include "comm_channel.h"
#include "comm_channel.c"

#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

#define NUM_MESSAGES 10000

MessageQueue q;

void *producer(void *arg) {
    for (int i = 0; i < NUM_MESSAGES; i++) {
        Message msg;
        char buffer[64];
        sprintf(buffer, "Message %d", i);
        encode_message(&msg, buffer);
        enqueue(&q, &msg);
    }
    return NULL;
}

void *consumer(void *arg) {
    int *count = (int *)arg;
    char buffer[64];
    for (int i = 0; i < NUM_MESSAGES; i++) {
        Message msg;
        dequeue(&q, &msg);
        decode_message(&msg, buffer);
        (*count)++;
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;
    int recv_count = 0;

    init_queue(&q);

    struct timeval start, end;
    gettimeofday(&start, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, &recv_count);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - start.tv_sec) * 1000.0;
    elapsed += (end.tv_usec - start.tv_usec) / 1000.0;

    printf("Test completed: %d/%d messages received.\n", recv_count, NUM_MESSAGES);
    printf("Elapsed time: %.2f ms\n", elapsed);
    printf("Throughput: %.2f messages/sec\n", NUM_MESSAGES / (elapsed / 1000.0));

    return 0;
}
