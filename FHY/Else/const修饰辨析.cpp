#include <iostream>
using namespace std;

int main()
{
    int b = 28;
    const int c = 1114;   //<-----WRONG!!!������仰����
    const int* pi0 = &b;     // OR int const *pi = &b;
    int* const pi1 = &c;
//    int a = 5;
//    pi = &a;

//    pi = &c;
    b++; //���const int* pi0 = &b,��(*pi0)++��������������b����һ��const�������޸�b�����޸�*pi0
   // pi1++��������
    cout << "*pi0 == " << *pi0 << endl;
    cout << "b == " << b << endl;

    //


    return 0;
}
//error: invalid conversion from 'const int*' to 'int*' [-fpermissive]|
