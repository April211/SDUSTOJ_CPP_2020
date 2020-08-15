#include <bits/stdc++.h>
using namespace std;

class Thing
{
private:
    string ss$;
public:
    Thing(string tt):ss$(tt){cout << "A thing named by " << ss$ << " is created!" << endl;}
    Thing(){cout << "A thing without name is created!" << endl;}
    Thing(const Thing &tt):ss$(tt.ss$)
    {
        if(ss$.empty())
        {
            cout << "A thing without name is copied!" <<endl;
        }
        else
        {
             cout << "A thing named by " << ss$ << " is copied!" <<endl;
        }
    }
    ~Thing()
    {
        if(ss$.empty())
        {
            cout << "A thing without name is erased!" <<endl;
        }
        else
        {
             cout << "A thing named by " << ss$ << " is erased!" <<endl;
        }
    }







};






int main()
{
    string name;
    Thing Thing1, Thing2(Thing1);
    cin>>name;
    Thing Thing3(name);
    Thing Thing4(Thing3);
    return 0;
}
