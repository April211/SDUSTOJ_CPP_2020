#include <iostream>
using namespace std;

int main()
{
    int v1 = 0, v2 = 0;
    int sum = 0;
    cout << "Please give me two numbers :" << endl ;    // ¼Ù¶¨v1>v2
    cin >> v1 >> v2 ;
    for(int i = v1 ; i<= v2 ; i++)
    {
        sum += i;
    }
    cout << "Sum from num1 to num2 :" << sum << endl ;



    return 0;
}
