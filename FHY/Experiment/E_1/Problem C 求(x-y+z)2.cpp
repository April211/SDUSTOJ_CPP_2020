#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int f(int x,int y = 1,int z = 0)
{
    int ans;
    ans = 2*(x - y + z);
    return ans;
}



int main()
{
    int n, x, y, z;
    while(cin>>n)
    {
        if(n == 3)
        {
            cin>>x>>y>>z;
            cout<<f(x, y, z)<<endl;
        }
        if(n == 2)
        {
            cin>>x>>y;
            cout<<f(x, y)<<endl;
        }
        if(n == 1)
        {
            cin>>x;
            cout<<f(x)<<endl;
        }
        if(n == 0)
            break;
    }
}
