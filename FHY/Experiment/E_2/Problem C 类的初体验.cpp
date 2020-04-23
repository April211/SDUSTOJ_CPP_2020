#include <iostream>
#include <iomanip>
using namespace std;

class Data
{
private:
    double _num;
public:
      Data(double d):_num(d){}

      double getValue()
      {
            return _num;
      }

      void showValue()
      {
            cout<< _num <<endl;
      }

};


int main()
{
    double d;
    cin>>d;
    Data data(d);
    cout<<data.getValue()<<endl;
    data.showValue();
}
