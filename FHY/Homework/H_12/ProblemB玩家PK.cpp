#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Role
{
protected:
    int hp$, ce$, de$, fa$;
    string name$;
public:
    Role():hp$(-1), ce$(-1), de$(-1), fa$(-1), name$("Default"){}
    Role(string name, int h, int c, int d, int f):name$(name), hp$(h), ce$(c), de$(d), fa$(f){}
    Role(const Role& tt):name$(tt.name$), hp$(tt.hp$), ce$(tt.ce$), de$(tt.de$), fa$(tt.fa$){}
    virtual ~Role(){}
    void combat(Role&);
    Role& facmps(Role&);
    Role& facmpb(Role&);
    void  attack(const Role&)const;
    int   whowins(const Role&)const;
};

int Role::whowins(const Role& tt)const
{
    if(this->hp$ == 0) { cout << tt.name$ << " wins." << endl; return 1;}
    else if(tt.hp$ == 0) { cout << this->name$ << " wins." << endl; return 1;}
    else{ return 0;}
}

void Role::attack(const Role& tt)const
{
     cout << this->name$ << " attacks " << tt.name$ << ':' << tt.name$ <<  " hp=" << tt.hp$ << ",de=" << tt.de$ << endl;
}

Role& Role::facmps(Role& another)//�����ȹ�ֵС��һ��
{
    if((*this).fa$ < another.fa$) { return *this;}
    else {return another;}  
}

Role& Role::facmpb(Role& another)//�����ȹ�ֵ���һ��
{
    if((*this).fa$ > another.fa$) { return *this;}
    else {return another;}  
}

void Role::combat(Role& another)
{
    while(1)
    {
        //���־֣���һ�֣�
        if((*this).facmps(another).de$ >= (*this).facmpb(another).ce$)//���ܹ����߷��������ڵ��ڹ����߹�����ʱ
        {
            if((--(*this).facmps(another).hp$)<0) { (*this).facmps(another).hp$ = 0;}//��һ��Ѫ����һ�������
            if((--(*this).facmps(another).de$)<0) { (*this).facmps(another).de$ = 0;}//��֤Ѫ���ͷ������ķǸ���
            (*this).facmpb(another).attack((*this).facmps(another));            //�����ι����Ľ��
            if(this->whowins(another)) break;                                       //�ж�һ�����־ֵ���Ӯ
        }
        else//(*this).facmps(another).de$ < (*this).facmpb(another).ce$
        {
            (*this).facmps(another).hp$ -= (*this).facmpb(another).ce$ - (*this).facmps(another).de$;
            if((*this).facmps(another).hp$<0)     { (*this).facmps(another).hp$ = 0;}
            if((--(*this).facmps(another).de$)<0) { (*this).facmps(another).de$ = 0;}
            (*this).facmpb(another).attack((*this).facmps(another));            //�����ι����Ľ��
            if(this->whowins(another)) break;                                       //�ж�һ�����־ֵ���Ӯ
        }
        //�ڶ��֣�������С�Ĺ�����������ģ�������������ܹ�����
        if((*this).facmpb(another).de$ >= (*this).facmps(another).ce$)//���ܹ����߷��������ڵ��ڹ����߹�����ʱ
        {
            if((--(*this).facmpb(another).hp$)<0) { (*this).facmpb(another).hp$ = 0;}//��һ��Ѫ����һ�������
            if((--(*this).facmpb(another).de$)<0) { (*this).facmpb(another).de$ = 0;}//��֤Ѫ���ͷ������ķǸ���
            (*this).facmps(another).attack((*this).facmpb(another));          //�ڶ��ֱض���������С�Ĺ������������
            if(this->whowins(another)) break;                                       //�ж�һ����Ӯ
        }
        else//(*this).facmpb(another).de$ < (*this).facmps(another).ce$
        {
            (*this).facmpb(another).hp$ -= (*this).facmps(another).ce$ - (*this).facmpb(another).de$;
            if((*this).facmpb(another).hp$<0)     { (*this).facmpb(another).hp$ = 0;}
            if((--(*this).facmpb(another).de$)<0) { (*this).facmpb(another).de$ = 0;}
            (*this).facmps(another).attack((*this).facmpb(another));            //�����ι����Ľ��
            if(this->whowins(another)) break;                                       //�ж�һ�����־ֵ���Ӯ
        }
    }
}


int main()
{
    int a, b, c, d;
    string name;
    cin>>name>>a>>b>>c>>d;
    Role one(name, a, b, c, d);
    cin>>name>>a>>b>>c>>d;
    Role two(name, a, b, c, d);
    one.combat(two);
    return 0;
}
/* 

Problem B: ���PK
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1434  Solved: 385
[Submit][Status]
Description
�ںܶ���Ϸ�У�������ҽ���PK��Player Killing����Ϸ������໥ս����ģʽ�����ж��Լ�ս������Ҫ�����������һ�¡�����һ����Role����ʾ��Ϸ��ҡ�����4���Ǹ��������ԣ�Ѫ����hp������������ce������������de�����ȹ�ֵ��fa�����Լ�һ����������ǳƵ�string����name��
PK���ûغ��ơ��������������A��B����A��B����PKʱ���ȹ�ֵ�ߵ�һ�����ȷ�����������A���ȹ�ֵ����B����ô��һ�غ��У�A���ȹ���B��B���������ţ����Bû���������򹥻�A��A���ڷ���״̬�����Aû�������������ڶ��غϡ�һֱ�ظ�������ȥ��ֱ��һ������Ϊֹ��
��һ��������ʱ����Ѫ���仯��ѭ���¹��򣺣�1��������������С�ڹ������Ĺ���������ô��Ѫ������1����2������������С�ڹ������Ĺ���������ô��Ѫ�����٣��Է��Ĺ�����-�Լ��ķ���������ͬʱ��ÿһ��������һ�Σ������������1��
���磺��A����Bʱ�����A�Ĺ�����Ϊ10��B�ķ�����Ϊ4����B��Ѫ������6������������1�����A�Ĺ�����Ϊ10��B�ķ��������ڵ���10����B��Ѫ���ͷ�����������1��
��Role�У���������������
��1��Role(string n, int h, int c, int d, int f)�����γ�ʼ���ǳơ�Ѫ���������������������ȹ�ֵ��������ҵ��ȹ�ֵ��ͬ��
��2��void combat(Role &another)������PK����չʾPK���̡�����PK��������ҷֱ���A��B����A����Bʱ����ʾ��
A attacks B:B hp=#,de=$
����#��$�ֱ���B���������ʣ��Ѫ���ͷ���������ʣ��Ѫ��С��0ʱ��Ҳ��ʾΪ0��������ʾ������
��B����Aʱ����ʾ��
B attacks A:A hp=%,de=&
����%��&�ֱ���A���������ʣ��Ѫ���ͷ���������ʣ��Ѫ��С��0ʱ��Ҳ��ʾΪ0��������ʾ������
��󣬵�A��Ѫ��Ϊ0ʱ�������
B wins.
��B��Ѫ��Ϊ0ʱ�������
A wins.

Input
�����У�ÿ�а���1���ַ���������ǳƣ���4������������Ӧ��ҵ�Ѫ���������������������ȹ�ֵ��

Output
��ǰ��������������

Sample Input
A 30 10 4 1
B 10 2 20 2
Sample Output
B attacks A:A hp=29,de=3
A attacks B:B hp=9,de=19
B attacks A:A hp=28,de=2
A attacks B:B hp=8,de=18
B attacks A:A hp=27,de=1
A attacks B:B hp=7,de=17
B attacks A:A hp=26,de=0
A attacks B:B hp=6,de=16
B attacks A:A hp=24,de=0
A attacks B:B hp=5,de=15
B attacks A:A hp=22,de=0
A attacks B:B hp=4,de=14
B attacks A:A hp=20,de=0
A attacks B:B hp=3,de=13
B attacks A:A hp=18,de=0
A attacks B:B hp=2,de=12
B attacks A:A hp=16,de=0
A attacks B:B hp=1,de=11
B attacks A:A hp=14,de=0
A attacks B:B hp=0,de=10
A wins.
HINT
Append Code
append.cc, */