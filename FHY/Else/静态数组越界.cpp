#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    char str[2];
    memset(str, 0, sizeof(str));
    str[0] = 'i';
    str[1] = 'j';
    printf("%c", str[2]);
    printf("------------");

    return 0;
}