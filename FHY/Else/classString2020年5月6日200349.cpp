#include <bits/stdc++.h>
using namespace std;

template <typename T>  //ģ��

class Array//array of T
{
private:
    T* element$;    //ָ���׸�Ԫ�صĵ�ַ
    int  length$;   //����
public:
    //���캯��
    Array():length$(0), element$(NULL){}
    Array(int ttlen):length$(ttlen), element$(NULL)
    {
        element$ = new T[length$];//��̬����ռ䣬ʵ�ʷ���size$��С
    }
    //��������
    ~Array(){delete []element$;}         //��������������ķ���
    T& operator[] (int i){ return element$[i]; }    //�±���������ء�ָ����Ϊ����������  
};


int main()
{
    Array <string> s(10);    //����һ���Զ�����������Ҫָ������.��<TYPE>
    s[0] = "1234";
    s[1] = "12345";
    s[2] = "123456";
    s[3] = "1234567";
    s[4] = "12345678";
    s[5] = "123456789";
    for(int i = 0; i < 6; i++)
    {
        cout << s[i] << ' ';         //�򵥵����string���ͣ�string�����Ѿ���<<����)��ʹ����operator overload
    }
    cout << "zzzz";


    return 0;
}