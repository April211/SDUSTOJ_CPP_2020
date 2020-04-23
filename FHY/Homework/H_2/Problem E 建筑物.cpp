#include <iostream>
#include <cstdio>
using namespace std;

typedef class
{
private:
    int cnt;
public:
    void setCnt(int c)
    {
        cnt = c;
    }
    int getCnt()
    {
        return cnt;
    }

} Building;

int main()
{
    Building b;
    int i;
    cin>>i;
    b.setCnt(i);
    cout<<"The building has "<<b.getCnt()<<" floors."<<endl;
    return 0;
}

