#include <iostream>
#include <cstdio>
using namespace std;

int select_sort(double* tt, int len)
{
    if(tt == NULL) {cout << "NUll POINTER! ERROR!" << endl; return 0;}
    for(int i = 0; i< len - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j< len; j++)
        {
            if(tt[j] < tt[min])   //这里由小到大排列
            {
                double temp;
                temp    =  j;
                j   =  temp;
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
    cout << "Before select sort: " << endl;
    printarray(pt, len);
    select_sort(pt, len);
    cout << "After select sort: " << endl;
    printarray(pt, len);



    return 0;
}