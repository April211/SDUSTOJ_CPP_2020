#include <iostream>
#include <string>
using namespace std;
int main ( )
{
    string str;  //������һ�����ַ���str
    str = "Hello_world!!!!!!!!!!!!!";   // ��str��ֵΪ"Hello world"
    char cstr[] = "abcde";  //������һ��C�ַ���
    string s1(str);       //���ø��ƹ��캯������s1��s1Ϊstr�ĸ���Ʒ
    cout<<s1<<endl;
    string s2(str,6);     //��str�ڣ���ʼ��λ��6�Ĳ��ֵ���s2�ĳ�ֵ
    cout<<s2<<endl;
    string s3(str,6,3);  //��str�ڣ���ʼ��6�ҳ��ȶ���Ϊ3�Ĳ�����Ϊs3�ĳ�ֵ
        cout<<s3<<endl;
    string s4(cstr);   //��C�ַ�����Ϊs4�ĳ�ֵ
    cout<<s4<<endl;
    string s5(cstr,3);  //��C�ַ���ǰ3���ַ���Ϊ�ַ���s5�ĳ�ֵ��
    cout<<s5<<endl;
    string s6(5,'A');  //����һ���ַ���������5��'A'�ַ�
    cout<<s6<<endl;
    string s7(str.begin(),str.begin()+5); //����str.begin()��str.begin()+5�ڵ��ַ���Ϊ��ֵ
    cout<<s7<<endl;
    return 0;
}
