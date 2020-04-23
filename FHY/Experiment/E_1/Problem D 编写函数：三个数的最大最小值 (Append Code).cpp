#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int get_num(int &x,int &y,int &z)
{
    cin >> x >> y >> z;
    return 0;
}
int max_min(int &nmax,int &nmin, int x, int y, int z)
{
    int t;
    if(x<y)
    {
        t = x;
        x = y;
        y = t;
    }
    if(y<z)
    {
        t = y;
        y = z;
        z = t;
    }
    if(x<y)
    {
        t = x;
        x = y;
        y = t;
    }
    nmax = x;
    nmin = z;
    return 0;
}

int main()
{
    int cases;
    int mmax, mmin, a, b, c;

    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        get_num(a, b, c);
        max_min(mmax, mmin, a, b, c);
        cout<<"case "<<i<<" : "<<mmax<<", "<<mmin<<endl;
    }
}
