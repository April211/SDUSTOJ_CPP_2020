#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template <typename T>

int Swap(T &x, T &y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;

    return 0;
}



int main()
{
    int x1, y1;

//    cin>>x1>>y1;
//    int* p1 = &x1, *p2 = &y1;
//    Swap(p1, p2);
//    cout<<*p1<<" "<<*p2<<endl;

    cin>>x1>>y1;
    Swap(x1, y1);
    cout<<x1<<" "<<y1<<endl;

//    double x2, y2;

//    cin>>x2>>y2;
//    Swap(&x2, &y2);
//    cout<<x2<<" "<<y2<<endl;

//    cin>>x2>>y2;
//    Swap(x2, y2);
//    cout<<x2<<" "<<y2<<endl;
}
