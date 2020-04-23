#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "Octal Decimal Hexadecimal" << endl;
    printf("%-6o%-8d%x\n", a, a, a);
    printf("%-6o%-8d%x", b, b, b);


    return 0;
}
