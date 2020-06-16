#include <iostream>
#include <iomanip>
#include <typeinfo>
using namespace std;


template <typename T>
class Sample
{
protected:
    T property$;
public:
    Sample(T property):property$(property){ cout << "Sample " << property$ << " is created." << endl;}
    Sample(const Sample& tt):property$(tt.property$){ cout << "Sample " << property$ << " is copied." << endl;}
    ~Sample(){}
    void add(const Sample);
    void show()const;

};


template <>
inline void Sample<double>::add(const Sample tt)
{
    (*this).property$ += (double)(tt.property$);
}

template<>
inline void Sample<int>::add(const Sample tt)
{
    property$ += (int)(tt.property$);
}

template<>
inline void Sample<double>::show()const
{
    cout << (double)property$ << endl;
}

template<>
inline void Sample<int>::show()const
{
    cout << (int)property$ << endl;
}


int main()
{
    int a, b;
    double c, d;
    cin>>a>>b>>c>>d;
    Sample<int> s1(a), s2(b), s3(s1);
    Sample<double> s4(c), s5(d), s6(s5);
    s1.add(s2);
    s1.show();
    s5.add(s4);
    s5.show();
    return 0;
}
/* 


Problem J: ��ģ��Sample
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1683  Solved: 1502
[Submit][Status]
Description
������ģ��Sample����ģ�����ΪT����Sample��ֻ��һ��T���͵����ԡ������乹�캯�����������캯����������������Ƶ���Ϣ������show������������ʾ����ֵ��ֻ�������ֵ��������add����������ǰ������Sample�����һ�����������ֵ��ӣ����Դ��뵱ǰ����

Input
����2��int����������2��double����ʵ����

Output
��������

Sample Input
1
2
1.6
3.356
Sample Output
Sample 1 is created.
Sample 2 is created.
Sample 1 is copied.
Sample 1.6 is created.
Sample 3.356 is created.
Sample 3.356 is copied.
Sample 2 is copied.
3
Sample 1.6 is copied.
4.956
HINT
Append Code
append.cc, */