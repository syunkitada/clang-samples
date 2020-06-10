#include <stdio.h>

int main(void) {
    {
        int num = 7;
        if (num > 10) {
            printf("if (num > 10)\n");
        } else if (num > 5) {
            printf("else if (num > 5)\n");
        } else {
            printf("else\n");
        }
    }

    {
        int num = 2;
        switch (num) {
            case 1:
                printf("switch 1\n");
                break;
            case 2:
                printf("switch 2\n");
                break;
            default:
                printf("switch default\n");
                break;
        }
    }

    {
        int n;
        for (n = 1; n <= 5; n++) {
            printf("for: %d\n", n);
        }
    }

    {
        int n = 2;
        while (n <= 5) {
            printf("while %d\n", n);
            n++;
        }
    }

    {
        int n;
        for (n = 1; n <= 5; n++) {
            if (n == 2) continue;
            if (n == 4) break;
            printf("for: %d\n", n);
        }
    }
}
