#include <iostream>
#include <iomanip>
using namespace std;

class Data
{
private:
    double _num;
public:
      Data(double d):_num(d){cout << "Initialize a data "<< _num << endl;}
      Data():_num(0){cout << "Initialize a data "<< _num << endl;}

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
    Data data1;
    double d;
    cin>>d;
    Data data(d);
    cout<<data.getValue()<<endl;
    data.showValue();
}
