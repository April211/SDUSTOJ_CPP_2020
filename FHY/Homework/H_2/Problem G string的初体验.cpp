#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    int a;
    getline(cin, s1);
    getline(cin, s2);
    cout << s1 << s2 << endl;
    if(s1 > s2)
    {
        cout << s2 << endl;
    }
    else
    {
        cout << s1 << endl;
    }

    string s3(s1.begin(), s1.begin()+4);//ÖÁ¶à4¸ö
    cout << s3;


    return 0;
}
