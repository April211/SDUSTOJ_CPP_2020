#include <iostream>
#include <iomanip>
using namespace std;

class Character
{
private:
    char _ch;
public:
    Character(char tch):_ch(tch){}
    Character toUpper()
    {
        if(islower(_ch))
        {
            _ch = toupper(_ch);
        }
        else
        {
            _ch = _ch;
        }
        return _ch;

    }
    Character toLower()
    {
        if(isupper(_ch))
        {
            _ch = tolower(_ch);
        }
        else
        {
            _ch = _ch;
        }
        return _ch;
    }
    void show(){cout << _ch;}
};



int main()
{
    int cases;
    char c;
    cin>>cases;
    cout<<"char"<<" upper"<<" lower"<<endl;
    for (int i = 0; i < cases; i++)
    {
        cin>>c;
        Character character(c);
        character.show();
        cout<<"    ";
        character.toUpper().show();
        cout<<"     ";
        character.toLower().show();
        cout<<endl;
    }
}
