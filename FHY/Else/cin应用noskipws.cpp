#include <iostream>

using namespace std;

int main()
{
    char c1, c2, c3, c4;
    char c5;
    cin >> noskipws >> c1 >> c2 >> c3 >> c4;
    cin >> skipws >> c5;
    cout << "--" << c1 << "--" << endl;
    cout << "--" << c2 << "--" << endl;
    cout << "--" << c3 << "--" << endl;
    cout << "--" << c4 << "--" << endl;
    cout << "--" << c5 << "--" << endl;

    return 0;
}
