#include <iostream>
using namespace std;

class Fruit
{
protected:
    string name$;
    double single$;
public:
    Fruit(string name, double single = 0.0):name$(name), single$(0.0){}
    virtual ~Fruit(){}
    virtual void input(){};
    virtual double total()const = 0;
};

class Apple: public Fruit
{
protected:
    double summ$;
public:
    Apple():Fruit("Apple"), summ$(0.0){}
    void input()
    {
        double tt = 0.0;
        cin >> single$ >> tt;
        summ$ += tt;
    }
    double total()const
    {
        double ans = 0.0;
        ans = single$* summ$* 30.0;
        return ans;

    }
};


class Banana: public Fruit
{
protected:
    double summ$;
public:
    Banana():Fruit("Banana"), summ$(0.0){}
    void input()
    {
        double tt = 0.0;
        cin >> single$ >> tt;
        summ$ += tt;
    }
    double total()const
    {
        double ans = 0.0;
        ans = single$* summ$* 25.0;
        return ans;

    }


};

class Pear: public Fruit
{
protected:
    double summ$;
public:
    Pear():Fruit("Pear"), summ$(0.0){}
    void input()
    {
        double tt = 0.0;
        cin >> single$ >> tt;
        summ$ += tt;
    }
    double total()const
    {
        double ans = 0.0;
        ans = single$* summ$* 20.0;
        return ans;

    }


};


int main()
{
    Fruit* fruit;
    string fruit_name;
    double sum = 0.0;
    int cases;
    cin >> cases;
    for(int i = 1; i <= cases; i++)
    {
        cin >> fruit_name;
        if(fruit_name == "Apple")
            fruit = new Apple();
        if(fruit_name == "Banana")
            fruit = new Banana();
        if(fruit_name == "Pear")
            fruit = new Pear();
        fruit->input();
        sum += fruit->total();
        delete fruit;
    }
    cout << "Total Price : " << sum << endl;
 
     return 0;
}

/* 

Problem C: ũ���԰
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 3046  Solved: 2504
[Submit][Status]
Description
���쵽�ˣ���԰���ˮ�������ˣ��̷�������ˮ���ˣ�ũ���Ƕ�ϣ���Լ���ˮ���������ü�Ǯ��
���ڹ�԰��������ˮ���������ۣ�ƻ����Apple�����㽶��Banana�����棨Pear����ÿ�����۶����¼��ˮ�������ࡢ���ۺ�������input()�������Զ�ȡÿ�����ۼ�¼�ĵ��ۺ�������total()�������Լ����������۵��ܼۡ�
���ǣ�����Ա�ڼ�¼ʱæ�г�������ˮ���ĵ��ۺ������ĵ�λû��ͳһ��������ÿ����ļ۸񣬶�ˮ���ǰ����¼�ġ����У�ƻ��һ�䰴30������㣬�㽶һ�䰴25������㣬��һ�䰴20������㡣ÿ��ˮ��ÿ�����۵��ܼ��ǡ�����*����*ÿ�乫��������
���ڣ��������һ�������æ�����԰����ˮ�����ܼۡ�����total()������ÿ��ˮ���ļ��㷽ʽ����һ�������ʹ�ö�̬��ʵ�֡�
-----------------------------------------------------------------------------
����Ʋ�ʵ�����ˮ�����������ϵ��ʹ��main()�����ܹ����в��õ���ȷ����������ø�ʽ��append.cc
Input
����ĵ�һ������n����ʾ������n��ˮ���չ��ļ�¼��ÿ����¼��Ϊ3���֣�ˮ�����ࡢ���ۺ�������

Output
���Ϊһ�У���ʾ������԰����ˮ�����ܼۡ�

Sample Input
5
Apple 4.2 100
Banana 8.8 50
Apple 4.5 200
Banana 7.8 100
Pear 3.7 100
Sample Output
Total Price : 77500
HINT
Append Code
append.c, append.cc, */