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

Problem A: QQ����
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 927  Solved: 215
[Submit][Status]
Description
QQ�Ѿ���Ϊ�ִ����������н��й�ͨ����������Ҫ�ֶΡ�ͨ���򵥳���QQ���ѵĹ������ͨ����������б�ʾ��
1. QQ�ࣺ����һ��int���͵����ԣ���ʾQQ���룻һ��string�������ԣ���QQ�ǳơ�������һ�����캯��QQ(int,string)�����ڳ�ʼ��������ԡ�
����QQ���뻥����ͬ��
2. Group�ࣺ���ڶԺ��ѽ��з��顣����һ��string���͵����ԣ���ʾ�������������һ������QQ���ѵ��б���QQ��Ķ�����б����������·�����
��1�����캯��Group(string)��
��2��void addQQ(const QQ&)��������б���׷�Ӻ��ѡ�
�������е�����������ͬ��
3. Friends�ࣺ����һ��Group��Ķ�����б����ٰ������·�����
��1��void addGroup(const Group&)��׷��һ�������顣
��2��void findGroup(string gName)�����ָ������gName�µ�����QQ���ѡ����ʱ�ĸ�ʽΪ��
Group # ��qq_id1 qq_name1; qq_id2 qq_name2; ......
���С�#����������������gName����qq_id1 qq_name1�����Ǹ�����QQ���ѵĺ�����ǳơ����ʱ��QQ������Ϣ֮����һ���ֺ�(;)��һ���ո���������һ��������һ�����(.)������QQ�����С�����˳�������
���������û�к��ѣ��������Group # ��empty.
���ָ�����鲻���ڣ��������Group # ��not existing.
��3��void findQq(int id)�����ָ����QQ����id�����ڵ������������ʽΪ��
QQ $ in : group_name1;group_name2;......
���У���$����ʾָ����QQ���룬������id��ֵ����group_name1�����Ǹú����Ӧ��QQ�������ڵ������б�����������С�������������֮����һ���ֺ�(;)��һ���ո���������һ��������һ�����(.)��
�����QQ�����ڣ��������QQ $ in : empty.

Input
�����кܶ��У���Ϊ�Ĳ��֡�
��һ����ֻ��һ�У���һ������M>0����ʾ֮����M�������顣
�ڶ�����������������Ϣ��ÿ����������������2���֣���һ����ֻ��һ�У����������������º��ѵĸ���N���ڶ�������N�У�ÿ����һ�����ѵĺ�����ǳơ�
�������ֵĵ�һ����һ������K>0����ʾ֮����K�У�ÿ����һ��������
���Ĳ��ֵĵ�һ����һ������L>0����ʾ֮����L�У�ÿ����һ��QQ���롣

Output
����������Ŀ������

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