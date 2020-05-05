#include <bits/stdc++.h>
using namespace std;

class Data
{
private:
    int da_int$;
    double da_dou$;
    unsigned flg$;//��һ����ǣ�
public:
    Data():flg$(1){cout << "A default object is created." << endl;}
    Data(int ttint):da_int$(ttint), flg$(2){cout << "An integer object " << da_int$ << " is created." << endl;}
    Data(double ttdou):flg$(3), da_dou$(ttdou){cout << "A double object " << da_dou$ << " is created." << endl;}
    ~Data()
    {
        if(flg$ == 3)
        {
            cout << "The double object " << da_dou$ << " is erased." << endl;
        }
        else if(flg$ == 2)
        {
            cout << "The integer object " << da_int$ << " is erased." << endl;
        }
        else//flg$ == 1
        {
            cout << "The default object is erased." << endl;
        }



    }


};



int main()
{
    Data d1;
    int i;
    cin>>i;
    Data d2(i);
    double d;
    cin>>d;
    Data d3(d);
    return 0;
}


//Problem B: ���Ϳɱ����
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 2498  Solved: 1209
//[Submit][Status]
//Description
//����һ��Data�࣬���ٰ���1��int���͵����ݳ�Ա��1��double���͵����ݳ�Ա�������乹�캯��������������ʹ�ó���ִ��ʱ���ܲ���������ʾ�Ľ����
//
//Input
//����2�У���1����1��int���͵����ݣ���2����1��double���͵����ݡ�
//
//Output
//��������
//
//Sample Input
//120
//3.14
//Sample Output
//A default object is created.
//An integer object 120 is created.
//A double object 3.14 is created.
//The double object 3.14 is erased.
//The integer object 120 is erased.
//The default object is erased.
//HINT
//Append Code
//append.cc,
