#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
    // Number
    int int1 = 2;            // 整数
    float float1 = 3.14159;  // 実数
    const int INT2 = 3;      // 定数

    printf("# Numbers\n");
    printf("int1: %d;\n", int1);
    printf("int2: %d;\n", INT2);
    printf("float1: %f;\n", float1);
    printf("(int)float1: %d;\n", (int)float1);  // Cast

    // Number Limit
    printf("short: min=%d, max=%d\n", SHRT_MIN, SHRT_MAX);   // short: min=-32768, max=32767
    printf("int: min=%d, max=%d\n", INT_MIN, INT_MAX);       // int: min=-2147483648, max=2147483647
    printf("long: min=%ld, max=%ld\n", LONG_MIN, LONG_MAX);  // long: min=-9223372036854775808, max=9223372036854775807
    printf("char: min=%d, max=%d\n", CHAR_MIN, CHAR_MAX);    // char: min=-128, max=127
    printf("float: min=%e, max=%e\n", FLT_MIN, FLT_MAX);     // float: min=1.175494e-38, max=3.402823e+38
    printf("double: min=%e, max=%e\n", DBL_MIN, DBL_MAX);    // double: min=2.225074e-308, max=1.797693e+308

    // Format
    printf("\n# Numbers Format\n");
    printf("int1: %5d;\n", int1);        // フィールド幅を5にする
    printf("int1: %-5d;\n", int1);       // フィールド幅を5にし、左詰めに
    printf("int1: %+d;\n", int1);        // 符号をつける
    printf("int1: %#o;\n", int1);        // 先頭0を付加(8進表示)
    printf("int1: %#x;\n", int1);        // 先頭に0int1を付加（16進表示）
    printf("float1: %05f;\n", float1);   // 幅を5にし、空白に0を詰める
    printf("float1: %5.2f;\n", float1);  // 幅を5にし、精度を2にする

    // Array
    int intArray1[3];
    intArray1[0] = 10;
    intArray1[1] = 20;
    intArray1[2] = 30;
    int intArray2[3] = {11, 22, 33};  // 定義および、初期化
    int intArray3[] = {44, 55, 66};   // サイズは省略可
    printf("\n# Arrays\n");
    printf("intArray1: %d, %d, %d\n", intArray1[0], intArray1[1], intArray1[2]);
    printf("intArray2: %d, %d, %d\n", intArray2[0], intArray2[1], intArray2[2]);
    printf("intArray3: %d, %d, %d\n", intArray3[0], intArray3[1], intArray3[2]);

    // Char Array
    char str1[4] = {'a', 'b', 'c', '\0'};
    char str2[] = {"def"};  // 上記を省略した初期化方法
    char str3[] = "ghi";    // 上記をさらに省略した初期化方法
    char *strp = "abc";     // ポインタを使って文字列を表現（これは配列ではない)
    printf("\n# Char Arrays\n");
    printf("str1: %c%c%c%c\n", str1[0], str1[1], str1[2], str1[3]);
    printf("str1: %s\n", str1);
    printf("str1: %s\n", &str1[0]);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
    printf("strp: %s\n", strp);

    // 文字コード
    // 各文字に割り当てられるバイトコード
    // 97にはaが割り当てられてるので、97をcharとして出力するとaが出力される
    printf("97=a: %c=%c\n", 97, 'a');

    return 0;
}
