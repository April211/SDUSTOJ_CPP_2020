#include <iostream>
#include <iomanip>
using namespace std;

class Number
{
public:
    double num0;
    void print();
    void vtest();
    void memory();
private:
    double num1;
    double temp;
};

void Number::print()
{
    double result = 0;
    result = (Number::num0)*(Number::num0);
    cout << result << '.' << endl;
}
void Number::vtest()
{
    clog << "Vtest has been successfully run." << endl;
}
void Number::memory()
{
    Number::num1 = Number::num0;
}
void All()
{
    clog << "I am in function All,now I am going to back into the main." << endl;
}
int main()
{
    Number a;
    cout << "Please give me a number :" << endl;
    cin >> a.num0;
    cout << "The square result of this given number is :";
    a.print();
    a.memory();
    All();
    clog << "I am back now." << endl;
    a.vtest();
    cout << "Now,GOOD-BYE!" << endl;


    return 0;
}


