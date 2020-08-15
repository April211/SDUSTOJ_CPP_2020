#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class QQ
{
protected:
    int accnum$;
    string nicknam$;
public:
    QQ() : accnum$(0) {}
    QQ(int accnum, string nicknam) : accnum$(accnum), nicknam$(nicknam) {}
    QQ(const QQ& tt):accnum$(tt.accnum$), nicknam$(tt.nicknam$){}
    virtual ~QQ() {}
    friend class Group;
    friend class Friends;
};

class Group
{
protected:
    string grname$;
    vector<QQ> flist$;
public:
    Group() {}
    Group(string grname) : grname$(grname) {}
    virtual ~Group() {}
    void addQQ(const QQ &tt) { flist$.push_back(tt); }
    friend class Friends;
};

class Friends
{
protected:
    vector<Group> grlist$;

public:
    Friends() {}
    virtual ~Friends() {}
    void addGroup(const Group &tt) { grlist$.push_back(tt); }
    void findGroup(string grname);
    void findQq(int id);
};

void Friends::findQq(int id)
{
    vector<Group>::iterator np1;
    vector<QQ>::iterator np2;
    int flag = 0;
    cout << "QQ " << id << " in :";
    vector<string> tt;
    vector<string>::iterator npt;
    for (np1 = grlist$.begin(); np1 != grlist$.end(); np1++)
    {
        for (np2 = (*np1).flist$.begin(); np2 != (*np1).flist$.end(); np2++)
        {
            if((*np2).accnum$ == id)
            {
                tt.push_back((*np1).grname$);
                break;
            }
        }
    }
    if(tt.empty()){ cout << " empty." << endl;}
    else
    {
        sort(tt.begin(), tt.end(), greater<string>());
        int size = tt.size();
        for(int i = 0; (i< size)&&(tt.size()!=0); i++)
        {
            if(tt.size() == 1)
            {
                cout << ' ' << tt[0] << '.' << endl;
                tt.pop_back();  //break
            }
            else if(tt.size() > 1)
            {
                cout << ' ' << tt[tt.size()-1] << ';';
                tt.pop_back();
            }
        }
    }
}
void Friends::findGroup(string grname)
{
    vector<Group>::iterator np1;
    vector<QQ>::iterator np2;
    int flag = 0;
    for (np1 = grlist$.begin(); np1 != grlist$.end(); np1++)
    {
        if ((*np1).grname$ == grname)
        {
            flag++;
            if ((*np1).flist$.empty())
            {
                cout << "Group " << grname << " : empty.";
            }
            else
            {
                cout << "Group " << grname << " :";
                //sort((*np1).flist$.begin(), (*np1).flist$.end(), less<int>());
                for(int i = 0; i< (*np1).flist$.size() - 1; i++)
                {
                    for(int j = 0; j< (*np1).flist$.size() - 1 - i; j++)
                    {
                        if((*np1).flist$[j].accnum$ > (*np1).flist$[j+1].accnum$)
                        {
                            QQ ttq = (*np1).flist$[j];
                            (*np1).flist$[j] = (*np1).flist$[j+1];
                            (*np1).flist$[j+1] = ttq;
                        }
                    }
                }
                for (np2 = (*np1).flist$.begin(); np2 != (*np1).flist$.end(); np2++)
                {
                    if(np2 != (*np1).flist$.end()-1)
                        cout << ' ' << (*np2).accnum$ << ' ' << (*np2).nicknam$ << ';';
                    else
                        cout << ' ' << (*np2).accnum$ << ' ' << (*np2).nicknam$ << '.';
                    
                }
            }
            cout << endl;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Group " << grname << " : not existing." << endl;
    }
}

int main()
{
    int m, n, i, j, id;
    string str;
    Friends friends;
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> str >> n;
        Group group(str);
        for (j = 0; j < n; j++)
        {
            cin >> id >> str;
            QQ qq(id, str);
            group.addQQ(qq);
        }
        friends.addGroup(group);
    }

    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> str;
        friends.findGroup(str);
    }

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        friends.findQq(j);
    }
    return 0;
}
/* 

Problem A: QQ好友
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 927  Solved: 215
[Submit][Status]
Description
QQ已经成为现代人们生活中进行沟通、交流的重要手段。通过简单抽象，QQ好友的管理可以通过如下类进行表示：
1. QQ类：包括一个int类型的属性，表示QQ号码；一个string类型属性，是QQ昵称。至少有一个构造函数QQ(int,string)，用于初始化相关属性。
假设QQ号码互不相同。
2. Group类：用于对好友进行分组。包括一个string类型的属性，表示好友组的组名；一个组内QQ好友的列表，即QQ类的对象的列表。至少有如下方法：
（1）构造函数Group(string)。
（2）void addQQ(const QQ&)：向好友列表中追加好友。
假设所有的组名互不相同。
3. Friends类：包括一个Group类的对象的列表。至少包括如下方法：
（1）void addGroup(const Group&)：追加一个好友组。
（2）void findGroup(string gName)：输出指定组名gName下的所有QQ好友。输出时的格式为：
Group # ：qq_id1 qq_name1; qq_id2 qq_name2; ......
其中“#”是组名，即参数gName。“qq_id1 qq_name1”等是该组内QQ好友的号码和昵称。输出时，QQ好友信息之间用一个分号(;)和一个空格隔开，最后一个后面有一个句点(.)。按照QQ号码从小到大的顺序输出。
如果该组中没有好友，则输出：Group # ：empty.
如果指定的组不存在，则输出：Group # ：not existing.
（3）void findQq(int id)：输出指定的QQ号码id所属于的组名。输出格式为：
QQ $ in : group_name1;group_name2;......
其中，“$”表示指定的QQ号码，即参数id的值。“group_name1”等是该号码对应的QQ好友所在的组名列表，按照组名从小到大输出。组名之间用一个分号(;)和一个空格隔开，最后一个后面有一个句点(.)。
如果该QQ不存在，则输出：QQ $ in : empty.

Input
输入有很多行，分为四部分。
第一部分只有一行，是一个整数M>0，表示之后有M个好友组。
第二部分输入好友组的信息。每个好友组的输入包括2部分：第一部分只有一行，包括组名及该组下好友的个数N。第二部分有N行，每行是一个好友的号码和昵称。
第三部分的第一行是一个整数K>0，表示之后有K行，每行是一个组名。
第四部分的第一行是一个整数L>0，表示之后有L行，每行是一个QQ号码。

Output
见样例和题目描述。

Sample Input
2
Friends 4
1 Jack
2 Tom
3 Mary
4 Richard
Enemies 2
4 Richard
2 Tom
2
Friends
enemy
2
1
2
Sample Output
Group Friends : 1 Jack; 2 Tom; 3 Mary; 4 Richard.
Group enemy : not existing.
QQ 1 in : Friends.
QQ 2 in : Enemies; Friends.
HINT
Append Code
append.cc, */