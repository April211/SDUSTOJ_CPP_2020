#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{

    int num[11];
    int i;
    memset(num, 0, sizeof(num));
    for(i=0; i<11; i++)    //1 28 99 10 10 83 66 27 38 13 12
    {
         scanf("%d", &num[i]);
    }
    for(i=0; i<11; i++)
    {
         printf("%d ", num[i]);
    }
    printf("\n");
    sort(num, num+11, greater<int>());  //std::less<int>()
    for(i=0; i<11; i++)
    {
         printf("%d ", num[i]);
    }






}
