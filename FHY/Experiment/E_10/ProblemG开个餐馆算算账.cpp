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

Problem G: 开个餐馆算算账
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2491  Solved: 1291
[Submit][Status]
Description
小明创业了！他开了一家餐馆，每天客人还挺多的。每天下班后，他都要算算今天总共收入多少钱，但是手工算太麻烦了，所以他来向你求助了。

Input
第1行N>0,表示餐馆提供N个菜品。

之后N行，每行包括2部分：菜名（不含空白符）及每份菜品的价格。

接着是M>0，表示今天接待的客人数。

每个客人的输入份三部分，第1行是客人的姓名（不含空白符），第2行是客人点的菜品的种类数K，之后K行是客人点的菜品名及份数。

Output
第一行输出Guest        Price。

之后按照客人姓名从小到大的顺序（没有重名的顾客），依次输出每个客人消费了多少钱，消费额保留2位小数。

输出时，姓名左对齐，宽度为所有客人姓名的最大长度加1。

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