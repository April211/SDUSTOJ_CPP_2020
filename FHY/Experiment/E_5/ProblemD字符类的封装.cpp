#include <bits/stdc++.h>
using namespace std;

class Character
{
private:
    char ch$;
public:
    Character():ch$(0){cout << "Default constructor is called!" << endl;}
    Character(char tt):ch$(tt){cout << "Character " << ch$ << " is created!" << endl;}
    ~Character(){cout << "Character " << ch$ << " is erased!" << endl;}
    void setCharacter(char tch){ch$ = tch;}
    int getAsciiCode(){return (int)ch$;}
    char getCharacter(){return ch$;}

};


int main()
{
    char ch;
    Character ch1, ch2('a');
    cin>>ch;
    ch1.setCharacter(ch);
    cout<<"ch1 is "<<ch1.getCharacter()<<" and its ASCII code is "<<ch1.getAsciiCode()<<"."<<endl;
    cout<<"ch2 is "<<ch2.getCharacter()<<" and its ASCII code is "<<ch2.getAsciiCode()<<"."<<endl;
    return 0;
}


/* Problem D: �ַ���ķ�װ
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 3884  Solved: 2948
[Submit][Status]
Description
��������ϰ�⣬�����ְɣ�������Ҫ������дһ��Character�࣬��char��һ�����������ͽ��з�װ����������Ҫ�����³�Ա������

1. �޲ι��캯����

2. ���캯��Character(char)���ò�����ʼ�����ݳ�Ա��

3. void setCharacter(char)�����������ַ�ֵ��

4. int getAsciiCode()�������ַ���ASII�롣

5. char getCharacter()�������ַ�ֵ��

6. ����������

Input
����ֻ��1�У�����һ���Ϸ��ġ��ɴ�ӡ���ַ���

Output
����кö��У���ο���������д��Ӧ�ĺ�����

Sample Input
c
Sample Output
Default constructor is called!
Character a is created!
ch1 is c and its ASCII code is 99.
ch2 is a and its ASCII code is 97.
Character a is erased!
Character c is erased!
HINT
Append Code
append.cc,
 */