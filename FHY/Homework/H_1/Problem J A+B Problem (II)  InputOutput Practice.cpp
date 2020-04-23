#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
    int a = 0, b = 0;
    int N;
    int i;
    cin >> N;
    for(i = 0;i < N;i++)
    {
        cin >> a >> b;
        if(N - i == 1)
        {
            cout << a + b;
        }
        else
        {
             cout << a + b << endl;
        }

    }






    return 0;
}
