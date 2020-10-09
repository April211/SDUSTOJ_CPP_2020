#include <stdio.h>
#include <stdlib.h>

void func1(int *pt, int a)
{
    printf("In function1: %d\n", pt);
    printf("In function1: %d\n", &pt);
    //pt = (int*)malloc(sizeof(int));
    *pt = a;        // 与上面那句看似很相似，但是产生的结果完全不同
    //pt = &a;      
}

void func1()
{

}


int main()
{
    int *pt;
    int  a = 4;
    printf("%d\n", pt);
    printf("%d\n", &pt);
    func1(pt, a);
    printf("%d\n", *pt);
    printf("%d\n", pt);
    printf("%d\n", &pt);

    return 0;
}