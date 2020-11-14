#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    char str[10];
    int N = 0;
    memset(str, 0, sizeof(str));
    scanf("%s%d", str, &N);
    printf("%s %d", str, N);


    return 0;
}