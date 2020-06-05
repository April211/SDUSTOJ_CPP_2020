#include <bits/stdc++.h>
using namespace std;

class Character
{
private:
    char ch$;
public:
    Character():ch$(0){}
    ~Character(){}
    friend istream& operator>> (istream& is, Character& chara);
    friend ostream& operator<< (ostream& os, Character& chara);
    friend char operator+ (Character& tt, int k);
    friend char operator- (Character& tt, int k);

};

istream& operator>> (istream& is, Character& chara)
{
    is >> chara.ch$;
    return is;
}
ostream& operator<< (ostream& os, Character& chara)
{
    char ch = chara.ch$;
    os << ch;
    return os;

}

char operator+ (Character& tt, int k)
{
    k %= 26;
    if(k < 0)
    {
        k = 26 + k;
    }
    return (int)tt.ch$ + k;
}
char operator- (Character& tt, int k)
{
    k %= 26;
    if(k > 0)
    {
        k = -(26 - k);
    }
    return (int)tt.ch$ - k;
}



int main()
{
    int cases, data;
    Character ch;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>ch;
        cin>>data;
        cout<<(ch + data)<<" "<<(ch - data)<<endl;
    }
}


/* Problem B: �����ַ��ļӼ���
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 5140  Solved: 3253
[Submit][Status]
Description
����һ���ַ���Character��ֻ��һ��char���͵����ݳ�Ա��

��������+��-��<<��>>�����������+��-�ĵڶ�����������int���͵�����n����+�����ڷ����Ե�ǰ�ַ�֮��ĵ�n���ַ�Ϊ����ֵ�Ķ��󣬡�-�����ڷ��ص�ǰ�ַ�֮ǰ�ĵ�n���ַ�Ϊ����ֵ�Ķ�����������ʾ��

Input
��1��N>0��ʾ��������������

ÿ�������ð���1���ַ���СдӢ����ĸ����1��int���͵�������

Output
�����N�У�ÿ�������Ӧһ�������ÿ�����������Ӧ�����ַ�֮��ĵ�n���ַ����Լ����ַ�֮ǰ�ĵ�n���ַ����������е�2�����������ַ��ǡ�a���������ǡ�1������ô��a��֮��ĵ�1���ַ��ǡ�b����"a"֮ǰ�ĵ�1���ַ��ǡ�z����ע�⣺��������������Ǹ�����

Sample Input
3
a 0
a 1
a -1
Sample Output
a a
b z
z b
HINT
Append Code
append.cc, */