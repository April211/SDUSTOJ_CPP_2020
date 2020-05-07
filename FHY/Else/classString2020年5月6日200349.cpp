#include <bits/stdc++.h>
using namespace std;

template <typename T>  //模板

class Array//array of T
{
private:
    T* element$;    //指向首个元素的地址
    int  length$;   //长度
public:
    //构造函数
    Array():length$(0), element$(NULL){}
    Array(int ttlen):length$(ttlen), element$(NULL)
    {
        element$ = new T[length$];//动态分配空间，实际分配size$大小
    }
    //析构函数
    ~Array(){delete []element$;}         //析构掉整个数组的方法
    T& operator[] (int i){ return element$[i]; }    //下标运算符重载。指针作为数组名来用  
};


int main()
{
    Array <string> s(10);    //定义一个自定义的数组对象，要指定类型.用<TYPE>
    s[0] = "1234";
    s[1] = "12345";
    s[2] = "123456";
    s[3] = "1234567";
    s[4] = "12345678";
    s[5] = "123456789";
    for(int i = 0; i < 6; i++)
    {
        cout << s[i] << ' ';         //简单的输出string类型（string类内已经对<<重载)，使用了operator overload
    }
    cout << "zzzz";


    return 0;
}