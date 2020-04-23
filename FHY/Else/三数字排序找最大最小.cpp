#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

int Sort(int &x, int &y, int &z, int &nmax, int &nmin)  //按照从大到小的次序
{
    int temp;
    if(x < y)//实质为冒泡排序
    {
        temp = x; x = y; y = temp;
    }
    if(y < z)
    {
        temp = y; y = z; z = temp;
    }
    if(x < y)
    {
        temp = x; x = y; y = temp;
    }
    nmax = x;
    nmin = z;

    return 0;

}
int main()
{
    int a, b, c;
    int mmax, mmin;
    cout << "Please enter 3 numbers: " << endl;
    cin >> a >> b >> c;
    Sort(a, b, c, mmax, mmin);
    cout << "After the Sort: " << endl;
    cout << a << ' ' << b << ' ' << c << endl;
    cout << "The maximum number among them is: " << endl;
    cout << mmax << endl;
    cout << "The minimum number among them is: " << endl;
    cout << mmin << endl;
}
