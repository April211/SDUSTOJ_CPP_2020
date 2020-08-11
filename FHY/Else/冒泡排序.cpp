#include <iostream>
#include <cstdio>
using namespace std;

int bubble_sort(double* tt, int len)
{
    if(tt == NULL) {cout << "NUll POINTER! ERROR!" << endl; return 0;}
    for(int i = 0; i< len - 1; i++)
    {
        for(int j = 0; j< len - i - 1; j++)
        {
            if(tt[j] > tt[j+1])   //这里由小到大排列
            {
                double temp;
                temp    =  tt[j];
                tt[j]   =  tt[j+1];
                tt[j+1] =  temp;
            }
        }
    }
    return 0;
}

int printarray(double* tt, int len)
{
    if(tt == NULL) {cout << "NUll POINTER! ERROR!" << endl; return 0;}
    for(int i = 0; i< len; i++)
    {
        if(i == 0) cout << tt[i];
        else cout << ' ' << tt[i];
    }
    cout << endl;
    return 0;
}


int main()
{
    int len = 0;
    cout << "Please enter the length of this new double array: " << endl;
    cin >> len;
    double* pt = new double [len];
    cout << "Please enter " << len << " numbers: " << endl;
    for(int i = 0; i< len; i++)
    {
        cin >> pt[i];
    }
    cout << "Before bubble sort: " << endl;
    printarray(pt, len);
    bubble_sort(pt, len);
    cout << "After bubble sort: " << endl;
    printarray(pt, len);

    return 0;
}