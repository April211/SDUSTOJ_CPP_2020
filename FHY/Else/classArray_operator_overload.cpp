#include <bits/stdc++.h>
using namespace std;

template <typename T>  //ģ��

class Array//int array
{
private:
    T* element$;    //ָ���׸�Ԫ�صĵ�ַ
    int  length$;   //����
    int  size$;   //��ֹ�ڴ���Ƭ������ʵ�ʷ���ֵ��2.7 OR 2*length$
public:
    //���캯��
    Array():length$(0), element$(NULL), size$(2*length$){}
    Array(int ttlen):length$(ttlen), element$(NULL), size$(2* length$)
    {
        element$ = new T[size$];//��̬����ռ䣬ʵ�ʷ���size$��С
    }
    //��������
    ~Array(){delete []element$;}         //��������������ķ���
    T& operator[] (int i){ return element$[i]; }    //ָ����Ϊ����������  
};


int main()
{
    Array <double> a(10);    //����һ���Զ�����������Ҫָ������.��<TYPE>

    for(int i = 0; i < 10; i++)
    {
        a[i] = i* 0.1;            //�򵥵ĸ�ֵ��ʹ����operator overload
    }
    for(int i = 0; i < 10; i++)
    {
        cout << a[i] << ' ';         //�򵥵������ʹ����operator overload
    }
    cout << endl;


    return 0;
}