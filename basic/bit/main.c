#include <stdio.h>

int main(void) {
    unsigned char a, o, x, n;
    unsigned char hoge, piyo, lshoge, rshoge;
    hoge = 187;  // 10111011
    piyo = 86;   // 01010110

    a = hoge & piyo;  // 00010010 = 2+16 = 18
    o = hoge | piyo;  // 11111111 = 255
    x = hoge ^ piyo;  // 11101101 = 1+4+8+32+64+128 = 237
    n = ~hoge;	// 01000100 = 4+64 = 68

    lshoge = hoge << 3;  // 11011000 = 8+16+64+128 = 216
    rshoge = hoge >> 3;  // 00010111 = 1+2+4+16=23

    printf("%d\n", a);
    printf("%d\n", o);
    printf("%d\n", x);
    printf("%d\n", n);
    printf("%d\n", lshoge);
    printf("%d\n", rshoge);

    printf("~0=%d\n", ~0);  // -1
    printf("~1=%d\n", ~1);  // -2
    printf("~2=%d\n", ~2);  // -3

    return 0;
}
