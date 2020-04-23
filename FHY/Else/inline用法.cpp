#include <iostream>
#include <iomanip>
using namespace std;

class Data
{
private:
    double _num;
public:
    Data(const double d):_num(d) {}
    double getValue()const;//只有类的成员函数才能定义为常量函数，普通函数不能定义为常量函数。
    void showValue()const;
};

inline double Data::getValue()const//只有类的成员函数才能定义为常量函数，普通函数不能定义为常量函数。
{
    return _num;
}

inline void Data::showValue()const
{
    cout<< _num <<endl;
}



int main()
{
    double d;
    cin>>d;
    Data data(d);
    cout<<data.getValue()<<endl;
    data.showValue();
}
