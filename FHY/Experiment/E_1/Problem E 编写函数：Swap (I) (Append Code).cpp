#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int Swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;

    return 0;
}
int Swap(double &x, double &y)
{
    double temp;
    temp = x;
    x = y;
    y = temp;

    return 0;
}
int Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

    return 0;
}
int Swap(double *x, double *y)
{
    double temp;
    temp = *x;
    *x = *y;
    *y = temp;

    return 0;
}



int main()
{
    int x1, y1;

    cin>>x1>>y1;
    Swap(&x1, &y1);
    cout<<x1<<" "<<y1<<endl;

    cin>>x1>>y1;
    Swap(x1, y1);
    cout<<x1<<" "<<y1<<endl;

    double x2, y2;

    cin>>x2>>y2;
    Swap(&x2, &y2);
    cout<<x2<<" "<<y2<<endl;

    cin>>x2>>y2;
    Swap(x2, y2);
    cout<<x2<<" "<<y2<<endl;
}
