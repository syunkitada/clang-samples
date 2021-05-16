#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_THREADS 10
#define MAX_CNT 50000
#define RESULT_LENGTH 100

void thread(void);
struct timespec start_time;

int main(void) {
    int i = 0;
    pthread_t thread_id[MAX_THREADS];
    void *thread_return;

    clock_gettime(CLOCK_REALTIME, &start_time);
    /* create new threads */
    for (i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&thread_id[i], NULL, (void *)thread, NULL) < 0) {
            perror("pthread_create error");
            exit(1);
        }
    }

    /* wait for the end of threads */
    for (i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(thread_id[i], &thread_return) < 0) {
            perror("pthread_join error");
            exit(1);
        }
    }

    return 0;
}

void thread(void) {
    int i = 0;
    clock_t start_clock, tmp_start_clock, tmp_clock, end_clock;

    unsigned int sec;
    int nsec;
    double d_sec;
    int tmp_msec;
    struct timespec end_time;

    int timestamps[RESULT_LENGTH];
    int timestamp_counter = 0;

    // スレッドが消費したCPU時間(CLOCKS_PER_SECで割ると秒になる)
    start_clock = clock();
    tmp_start_clock = clock();

    for (i = 0; i < MAX_CNT; i++) {
        tmp_clock = clock();
        if ((double)(tmp_clock - tmp_start_clock) / CLOCKS_PER_SEC > 0.001) {
            clock_gettime(CLOCK_REALTIME, &end_time);
            sec = end_time.tv_sec - start_time.tv_sec;
            nsec = end_time.tv_nsec - start_time.tv_nsec;
            tmp_msec = (int)((double)sec + (double)nsec / (1000 * 1000));
            timestamps[timestamp_counter] = tmp_msec;
            timestamp_counter++;
            if (timestamp_counter >= RESULT_LENGTH) {
                break;
            }
            tmp_start_clock = tmp_clock;
        }

        if ((double)(clock() - start_clock) / CLOCKS_PER_SEC > 0.1) {
            break;
        }
    }

    // 計測時間
    clock_gettime(CLOCK_REALTIME, &end_time);
    sec = end_time.tv_sec - start_time.tv_sec;
    nsec = end_time.tv_nsec - start_time.tv_nsec;
    d_sec = (double)sec + (double)nsec / (1000 * 1000 * 1000);

    char result[RESULT_LENGTH];
    for (i = 0; i < RESULT_LENGTH; i++) {
        result[i] = '_';
    }
    for (i = 0; i < RESULT_LENGTH; i++) {
        if (timestamps[i] > 0) {
            if (timestamps[i] >= RESULT_LENGTH) {
                continue;
            }
            result[timestamps[i]] = '+';
        }
    }
    // MEMO: pthread_selfはスレッドのIDを返す
    printf("thread[%lu] elapsed=[%f] %s\n", pthread_self(), d_sec, result);

    pthread_exit(0);
}
