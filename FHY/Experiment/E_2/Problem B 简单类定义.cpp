#include <iostream>
#include <iomanip>
using namespace std;

class Test
{
private:
    int _member;
public:
    Test(int temp = 0):_member(temp){cout << "Test " << _member << " is created." << endl;}
    ~Test(){cout << "Test " << _member << " is erased." << endl;}
    int getMem()
    {
        return _member;
    }
    int setMem(int a)
    {
        _member = a;
        return 0;
    }

};
int main()
{
    Test t1;
    int i;
    cin>>i;

    Test t2(i);
    cout<<"t2 is "<<t2.getMem()<<"."<<endl;
    cin>>i;
    t2.setMem(i);
    cout<<"t2 is "<<t2.getMem()<<"."<<endl;
    return 0;
}
