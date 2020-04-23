#include <bits/stdc++.h>
using namespace std;

//定义类 Data
class Data
{
private:
    double $num;
    static int $pcs;//As a counter.被此类的所有对象共享
public:
    Data(double);
    Data();//声明构造函数，定义部分放到外面
    void getValue(double);
    void showValue()const;  //只有类的成员函数才能定义为常量函数，普通函数不能定义为常量函数。
    void showPcs()const;   //还有，区别于带const参数的函数

};
//下面是 定义类中的方法的部分
inline Data::Data(double d):$num(d) { ++$pcs;}

inline Data::Data(){ ++$pcs; }

inline void Data::getValue(double a) { $num = a; }

inline void Data::showValue()const { cout << $num << endl; }

inline void Data::showPcs()const { cout << $pcs << endl; }

int Data::$pcs = 0;//定义static量

int main()
{
    Data datum0{9.0}, *pi, *arr[10];//定义类指针时不调用构造函数
    pi = new Data[10];
    static Data sta0(7.0);
//   pi -> getValue(8.0);
    pi -> getValue(1114.0);
    (pi + 1) -> getValue(1115.0);

    datum0.showValue();
    pi -> showValue();
    (pi + 1) -> showValue();
    sta0.showValue();
    datum0.showPcs();        //_pcs is in private.   Output: 12.
    cout << "---------------" << endl;
    for(int i = 0; i < 10; i++)
    {
        arr[i] = new Data(11.0);
        arr[i] -> showValue();
    }
    arr[9] -> showPcs();//Output: 22.



    delete pi;


}

