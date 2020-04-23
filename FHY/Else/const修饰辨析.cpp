#include <iostream>
using namespace std;

int main()
{
    int b = 28;
    const int c = 1114;   //<-----WRONG!!!加上这句话不过
    const int* pi0 = &b;     // OR int const *pi = &b;
    int* const pi1 = &c;
//    int a = 5;
//    pi = &a;

//    pi = &c;
    b++; //如果const int* pi0 = &b,则(*pi0)++不被允许，但是若b不是一个const，可以修改b进而修改*pi0
   // pi1++不被允许
    cout << "*pi0 == " << *pi0 << endl;
    cout << "b == " << b << endl;

    //


    return 0;
}
//error: invalid conversion from 'const int*' to 'int*' [-fpermissive]|
