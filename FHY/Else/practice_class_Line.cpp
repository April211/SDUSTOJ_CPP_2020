#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    Point(int x, int y):x$(x), y$(y){}
    ~Point(){cout << "" << endl;}
    void showpoint()const;

private:
    double x$, y$;
};

inline void showpoint()const
{
    cout << "Point :(" << x$ << ", " << y$ << ')' << endl;


}
