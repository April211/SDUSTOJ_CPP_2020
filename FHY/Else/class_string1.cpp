#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int loc;
    const string s="study hard and make progress everyday! every day!!";

    loc=s.rfind("make",10);//index10往前找
    cout<<"the word make is at index"<<loc<<endl;//-1表示没找到
    loc=s.rfind("make");//缺省状态下，从最后一个往前找
    cout<<"the word make is at index"<<loc<<endl;
    loc=s.find_first_of("day");
    cout<<"the word day(first) is at index "<<loc<<endl;
    loc=s.find_first_not_of("study");
    cout<<"the first word not of study is at index"<<loc<<endl;
    loc=s.find_last_of("day");
    cout<<"the last word of day is at index"<<loc<<endl;
    loc=s.find("day");//缺陷状态下从第一个往后找
    cout<<loc<<endl;
    cout<<'\n';

    const string s1 = "lyy is mulushu, but lyy is quiet";
    const string s2 = "but";
    const char *s3 = "lyy";
    printf("Length: %d\n", s1.length());
    cout << s1.rfind(s2) << endl;
    printf("%d\n", (s1.rfind(s2, 1) == string::npos)?(-1):(1));
    cout << s1.rfind(s3, 40, 0) << endl;
    cout << s1.rfind(s3, 40, 3) << endl;
    cout << s1.rfind('t', 20) << endl;
    return 0;
}

//string (1)
//size_t rfind (const string& str, size_t pos = npos) const noexcept;
//c-string (2)
//size_t rfind (const char* s, size_t pos = npos) const;
//buffer (3)
//size_t rfind (const char* s, size_t pos, size_t n) const;
//character (4)
//size_t rfind (char c, size_t pos = npos) const noexcept;:
