#include <stdio.h>

// 構造体の型の定義
struct Student {
    char name[20];
    int age;
};

void strCopy(char *dest, const char *src) {
    while (*dest++ = *src++)
	;
}

int main(void) {
    // 構造体の宣言
    struct Student st;
    struct Student *pst;

    // 構造体のメンバにアクセスするには、.で区切って指定します
    strCopy(st.name, "hoge");
    st.age = 20;
    printf("st.name=%s: st.age=%d\n", st.name, st.age);

    pst = &st;
    // ポインタで構造体を参照し、そのメンバにアクセスする場合は、アロー演算子 -> を使います
    printf("pst->name=%s: pst->age=%d\n", pst->name, pst->age);
    strCopy(pst->name, "piyo");
    pst->age = 30;
    printf("pst->name=%s: pst->age=%d\n", pst->name, pst->age);

    // structは以下のように、初期化することができる
    struct Student st2 = {"hoo", 15};
    struct Student sts[3] = {
	{"x", 17},
	{"y", 18},
	{"z", 19},
    };
    printf("st2.name=%s, st2.age=%d\n", st2.name, st2.age);
    printf("sts[0].name=%s, sts[0].age=%d\n", sts[0].name, sts[0].age);
    printf("sts[1].name=%s, sts[1].age=%d\n", sts[1].name, sts[1].age);

    return 0;
}
