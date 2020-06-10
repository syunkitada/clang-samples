#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
    // typedef
    // 独自のtypeを定義することができる
    typedef unsigned char u8;
    typedef unsigned short u16;
    typedef unsigned int u32;
    typedef unsigned long u64;
    u8 a = 10;
    printf("u8: %d\n", a);

    typedef struct StudentTag {
        char name[20];
        int age;
    } Student;
    Student st = {
        "hoge",
        20,
    };
    printf("name=%s, age=%d\n", st.name, st.age);

    // union
    // 一つのメモリ領域に複数の変数を割り当てることができる
    typedef struct {
        union {
            struct {
                u32 vip_prefix_index;
                u16 port;
                u8 protocol;
                u8 rsv;
            };
            u64 as_u64;
        };
    } vip_port_key_t;

    vip_port_key_t key = {
        1,
        80,
        4,
        0,
    };
    printf("key=%ld\n", key.as_u64);

    // enum
    // 0から1ずつ増える定数を定義できる
    typedef enum {
        LB_NEXT_DROP,
        LB_N_NEXT,
    } lb_next_t;
    lb_next_t next = LB_NEXT_DROP;
    printf("next=%d\n", next);
    next = LB_N_NEXT;
    printf("next=%d\n", next);

    switch (next) {
        case LB_NEXT_DROP:
            printf("drop\n");
            break;
        case LB_N_NEXT:
            printf("next\n");
            break;
    }

    char *nextNodes[] = {
        [LB_NEXT_DROP] = "drop",
        [LB_N_NEXT] = "next",
    };
    printf("nextNodes[0]=%s\n", nextNodes[0]);
    printf("nextNodes[1]=%s\n", nextNodes[1]);

    return 0;
}
