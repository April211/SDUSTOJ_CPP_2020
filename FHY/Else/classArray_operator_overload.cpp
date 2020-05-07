#include <bits/stdc++.h>
using namespace std;

template <typename T>  //模板

class Array//int array
{
private:
    T* element$;    //指向首个元素的地址
    int  length$;   //长度
    int  size$;   //防止内存碎片化，即实际分配值：2.7 OR 2*length$
public:
    //构造函数
    Array():length$(0), element$(NULL), size$(2*length$){}
    Array(int ttlen):length$(ttlen), element$(NULL), size$(2* length$)
    {
        element$ = new T[size$];//动态分配空间，实际分配size$大小
    }
    //析构函数
    ~Array(){delete []element$;}         //析构掉整个数组的方法
    T& operator[] (int i){ return element$[i]; }    //指针作为数组名来用  
};


int main()
{
    Array <double> a(10);    //定义一个自定义的数组对象，要指定类型.用<TYPE>

    for(int i = 0; i < 10; i++)
    {
        a[i] = i* 0.1;            //简单的赋值，使用了operator overload
    }
    for(int i = 0; i < 10; i++)
    {
        cout << a[i] << ' ';         //简单的输出，使用了operator overload
    }
    cout << endl;


    return 0;
}