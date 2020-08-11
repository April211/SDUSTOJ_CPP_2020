#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    unsigned short int ui;
    signed short int si;
    ui = (unsigned short int)0x8000u;
    si = (signed short int)0x8000;
    printf("ui = %u\n", ui);
    printf("si = %d\n", si);
    ui = ui >> 1;
    si = si >> 1;
    printf("ui = %u\n", ui);
    printf("si = %d\n", si);
    cout << "------------------------------" << endl;

    ui = (unsigned short int)0x8000u;
    si = (signed short int)0x8000;
    printf("%u\n", ui);
    printf("%d\n", si);
    ui = ((signed short int)ui >> 1);
    si = ((unsigned short int)si >> 1);
    printf("%u\n", ui);
    printf("%d\n", si);
    cout << "------------------------------" << endl;

    ui = (unsigned short int)0x8000u;
    si = (signed short int)0x8000;
    printf("%u\n", ui);
    printf("%d\n", si);
    ui = ui << 1;
    si = si << 1;
    printf("%u\n", ui);
    printf("%d\n", si);
    cout << "-------------------------------" << endl;

    ui = (unsigned short int)0x8000u;
    si = (signed short int)0x8000;
    printf("%u\n", ui);
    printf("%d\n", si);
    ui = ((signed short int)ui << 1);
    si = ((unsigned short int)si << 1);
    printf("%u\n", ui);
    printf("%d\n", si);
    return 0;
}
