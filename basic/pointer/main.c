#include <stdio.h>

void swap(int *x, int *y);
void echo1(char str[]);
void echo2(char *str);

int main(void) {
    int hoge;       // 通常の変数（この値はメモリ上に保存されています）
    int *phoge;     // ポインタ宣言（ポインタの型は参照先の方に合わせます）
    phoge = &hoge;  // &は、hogeのメモリアドレスを取得する
    hoge = 10;
    printf("hoge: %d\n", hoge);
    printf("hoge address: %p\n", phoge);  // hogeのメモリアドレス

    // *は、関節演算子とよばれるもので、このポインタのアドレスが指し示しめす先を参照する
    printf("phoge: %d\n", *phoge);
    *phoge = 20;
    printf("hoge: %d\n", hoge);

    int foo = 10, bar = 20;
    printf("foo: %d, bar: %d\n", foo, bar);
    swap(&foo, &bar);  // foo, barのメモリアドレスを引数として送る
    printf("foo: %d, bar: %d\n", foo, bar);

    printf("sizeof int: %ld\n", sizeof(hoge));    // 4
    printf("sizeof int*: %ld\n", sizeof(phoge));  // 8

    // Array and Pointer
    int array[] = {1, 2, 3};
    int *pArray;
    pArray = &array[0];  // iteratorにarrayの先頭アドレスを代入する
    pArray = array;      // 上記をこのように省略することもできる

    printf("array[0] address: %p: %d\n", &array[0], array[0]);
    printf("array[1] address: %p: %d\n", &array[1], array[1]);
    printf("array[2] address: %p: %d\n", &array[2], array[2]);

    // *(pArray + 1)は、pArrayのアドレス番地に1足して、そのアドレスの参照先を取得している
    printf("pArray: %d\n", *(pArray + 1));
    printf("pArray: %d\n", pArray[1]);  // p[1]は、*(pArray + 1)の省略表現

    pArray = &array[1];
    printf("pArray: %d\n", pArray[1]);   // array[2]を参照
    printf("pArray: %d\n", pArray[-1]);  // array[0]を参照

    char str[10] = "hello";
    echo1(str);
    echo2(str);

    return 0;
}

void swap(int *x, int *y) {  // メモリアドレスを受け取り、ポインタを初期化
    int temp = *x;	   // xの参照先をtempに保存
    *x = *y;		     // xの参照先にyの参照先の値を保存
    *y = temp;		     // yの参照先にtempの値を保存
}

// 配列は関数の引数として渡されるとき、ポインタとして渡される
// 関数呼び出しすると、仮引数のためのデータコピーが発生するため、ポインタのほうが効率がよい
void echo1(char str[]) { puts(str); }
// 以下の書き方は、上記と全く同じ意味を持つ
void echo2(char *str) { puts(str); }

