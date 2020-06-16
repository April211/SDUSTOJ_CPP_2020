#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
    int N = 0, M = 0;
    map <string, double, less<string> > menu;
    map <string, double, less<string> > guest;
    cin >> N;
    for(int i = 0; i< N; i++)
    {
        string dname; double price;
        cin >> dname >> price;
        menu.insert(make_pair(dname, price));
    }
    cin >> M;
    int namelen = 0;
    for(int i = 0; i< M; i++)
    {
        string gname; int num; double sprice = 0.0;
        cin >> gname;
        cin >> num;
        if(gname.length() > namelen){namelen = gname.length();}
        for(int j = 0; j< num; j++)
        {
            string dname; double num = 0;
            map <string, double, less<string> >::iterator pt;
            cin >> dname >> num;
            pt = menu.find(dname);
            sprice += (pt->second)* num;
        }
        guest.insert(make_pair(gname, sprice));
    }
    cout << setiosflags(ios::left) << setw(namelen+1) << setfill(' ') << "Guest";
    cout << "Price" << endl;
    map <string, double, less<string> >::iterator pt = guest.begin();
    for(int i = 0; i< guest.size(); i++)
    {
        cout << setw(namelen+1) << setfill(' ') << pt->first;
        cout << fixed << setprecision(2) << pt->second;
        pt++, cout << endl;
    }
    return 0;
}

/* 

Problem G: �����͹�������
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2491  Solved: 1291
[Submit][Status]
Description
С����ҵ�ˣ�������һ�Ҳ͹ݣ�ÿ����˻�ͦ��ġ�ÿ���°������Ҫ��������ܹ��������Ǯ�������ֹ���̫�鷳�ˣ������������������ˡ�

Input
��1��N>0,��ʾ�͹��ṩN����Ʒ��

֮��N�У�ÿ�а���2���֣������������հ׷�����ÿ�ݲ�Ʒ�ļ۸�

������M>0����ʾ����Ӵ��Ŀ�������

ÿ�����˵�����������֣���1���ǿ��˵������������հ׷�������2���ǿ��˵�Ĳ�Ʒ��������K��֮��K���ǿ��˵�Ĳ�Ʒ����������

Output
��һ�����Guest        Price��

֮���տ���������С�����˳��û�������Ĺ˿ͣ����������ÿ�����������˶���Ǯ�����Ѷ��2λС����

���ʱ����������룬���Ϊ���п�����������󳤶ȼ�1��

Sample Input
10
Yu-Shiang-Shredded-Pork 20
sweet-sour-Shredded-potato 15
Pie 0.50
Steamed-Rice 1.50
Tomato-and-Egg-Soup 17
Spareribs-with-brown-sauce 55
Sauteed-Sliced-Lamb-with-Scallion 60
Stir-fried-bean-sprouts 14
Moo-Shu-Pork 18
Deep-Fried-Dough-Sticks 2.50
3
Zhangsan
4
Yu-Shiang-Shredded-Pork 1
sweet-sour-Shredded-potato 1
Pie 3
Steamed-Rice 1
LiSi
2
Moo-Shu-Pork 1
Deep-Fried-Dough-Sticks 4
WangWu
3
Tomato-and-Egg-Soup 1
Spareribs-with-brown-sauce 1
Sauteed-Sliced-Lamb-with-Scallion 1
Sample Output
Guest    Price
LiSi     28.00
WangWu   132.00
Zhangsan 38.00
HINT
Append Code */