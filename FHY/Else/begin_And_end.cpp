#include <iterator>
#include <iostream>
using namespace std;


int main()
{

    int a[] = { 1,2,3,4,5,6,7,8,9,10 };

    for (int *p = begin(a); p != end(a); p++)
    {
         cout << *p << ",";
    }

    cout << endl; 

}
