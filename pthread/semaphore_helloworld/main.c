#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <semaphore.h>

struct thdata {
    char letter;
    pthread_t th;
    sem_t sync;
    sem_t start;
};

void *thread_function(void *thdata) {
    struct thdata *priv = (struct thdata *)thdata;

    /* sync */
    sem_post(&priv->sync);
    sem_wait(&priv->start);

    /* write my letter */
    putchar(priv->letter);

    /* sync */
    sem_post(&priv->sync);

    /* done */
    return (void *)NULL;
}

int main(void) {
    int rtn, i;
    struct thdata *thdata;
    char hello[128] = "Hello World!\n";

    /* initialize thread data */
    thdata = calloc(sizeof(struct thdata), strlen(hello));
    if (thdata == NULL) {
        perror("calloc()");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < strlen(hello); i++) {
        thdata[i].letter = hello[i];
        sem_init(&thdata[i].sync, 0, 0);   // セマフォの初期化
        sem_init(&thdata[i].start, 0, 0);  // セマフォの初期化
        rtn = pthread_create(&thdata[i].th, NULL, thread_function,
                             (void *)(&thdata[i]));
        if (rtn != 0) {
            fprintf(stderr, "pthread_create() #%0d failed for %d.", i, rtn);
            exit(EXIT_FAILURE);
        }
    }

    /* synchronization */
    for (i = 0; i < strlen(hello); i++) {
        // sem_waitは、threadがsem_post(&priv->sync); するまで待つ
        // sem_waitは、sem > 0 なら sem から 1 減算します
        // sem_waitは、sem が 0なら呼び出したスレッドはブロックされる
        sem_wait(&thdata[i].sync);
    }

    // 各スレッドと同期しながら一文字づつ表示する
    for (i = 0; i < strlen(hello); i++) {
        // threadが再開させる
        // semに1加算する
        sem_post(&thdata[i].start);

        // threadが出力し終わると、sem_post(&priv->sync);がよばれて次に進む
        sem_wait(&thdata[i].sync);
    }

    /* join */
    for (i = 0; i < strlen(hello); i++) {
        pthread_join(thdata[i].th,
                     NULL);  // スレッドの終了コードを取得し、スレッドを解放する
        sem_destroy(&thdata[i].sync);   // セマフォを破壊する
        sem_destroy(&thdata[i].start);  // セマフォを破壊する
    }

    free(thdata);
    exit(EXIT_SUCCESS);
}
