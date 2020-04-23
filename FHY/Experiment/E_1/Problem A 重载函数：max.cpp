#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int max(int a,int b)
{
    int c;
    a>b?(c = a):(c = b);
    return c;
}

double max(double a,double b)
{
    double c;
    a>b?(c = a):(c = b);
    return c;
}

int main()
{
    int a,b;
    double c,d;
    cin>>a>>b;
    cout<<max(a,b)<<endl;
    cin>>c>>d;
    cout<<max(c,d)<<endl;
    return 0;
}
