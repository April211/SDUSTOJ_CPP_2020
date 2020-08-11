#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main()
{
    double a = 11111111.222222222, c = 111111.1;
    int b = 12322222;

//    cout << setiosflags(ios::hex) << b << endl;
//    cout << b << endl;

//    cout << hex;
//    cout << b << endl;
//    cout << setiosflags(ios::uppercase);
//    cout << b << endl;
//    cout << resetiosflags(ios::uppercase);
//    cout << b << endl;
//    cout << setiosflags(ios::showbase | ios::uppercase);
//    cout << b << endl;
//    cout << dec;
//    cout << b << endl;

      cout.setf(ios::hex, ios::basefield);
      cout << 111 << endl;



//    cout << c << endl;
//    cout << b << endl;
//   cout << showpoint << fixed << setprecision(0) << 123.2222222222 <<endl;
//  printf("%.2lf\n",123.2222222222);






    return 0;
}
