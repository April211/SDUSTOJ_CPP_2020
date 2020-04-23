#include <iostream>
#include <iomanip>
using namespace std;

class Data
{
private:
    double _num;
public:
    Data(const double d):_num(d) {}
    double getValue()const;//ֻ����ĳ�Ա�������ܶ���Ϊ������������ͨ�������ܶ���Ϊ����������
    void showValue()const;
};

inline double Data::getValue()const//ֻ����ĳ�Ա�������ܶ���Ϊ������������ͨ�������ܶ���Ϊ����������
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
