#include <iostream>
using std::cout;
using std::cin;
using std::endl;

double area(double r=1.0)
{
    const double PI = 3.14;
    double S;
    S = PI*r*r;
    return S;
}


int main()
{
    double r;
    cin>>r;
    cout<<area(r)<<endl;
    cout<<area()<<endl;
    return 0;
}
