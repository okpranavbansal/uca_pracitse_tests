#include <stdio.h>

int main()
{
    int x, y;
    x = 6, y = 5;

    // bitAnd
    // printf("%d\n", x & y);
    printf("%d\n", ~(~x | ~y));

    // bitXor
    // printf("%d\n", x ^ y);
    printf("%d\n", ~(~(~x & y) & ~(x & ~y)));
}
__EDG_SIZE_TYPE__