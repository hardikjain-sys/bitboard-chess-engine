#include <stdio.h>
#include "utils.h"

void ps(int square)
{
    char c = 'a' + (square % 8);
    char r = '8' - (square / 8);

    printf("%c%c\n", c, r);
}