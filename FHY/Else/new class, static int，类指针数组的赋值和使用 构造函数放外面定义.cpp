#include <bits/stdc++.h>
using namespace std;

//������ Data
class Data
{
private:
    double $num;
    static int $pcs;//As a counter.����������ж�����
public:
    Data(double);
    Data();//�������캯�������岿�ַŵ�����
    void getValue(double);
    void showValue()const;  //ֻ����ĳ�Ա�������ܶ���Ϊ������������ͨ�������ܶ���Ϊ����������
    void showPcs()const;   //���У������ڴ�const�����ĺ���

};
//������ �������еķ����Ĳ���
inline Data::Data(double d):$num(d) { ++$pcs;}

inline Data::Data(){ ++$pcs; }

inline void Data::getValue(double a) { $num = a; }

inline void Data::showValue()const { cout << $num << endl; }

inline void Data::showPcs()const { cout << $pcs << endl; }

int Data::$pcs = 0;//����static��

int main()
{
    Data datum0{9.0}, *pi, *arr[10];//������ָ��ʱ�����ù��캯��
    pi = new Data[10];
    static Data sta0(7.0);
//   pi -> getValue(8.0);
    pi -> getValue(1114.0);
    (pi + 1) -> getValue(1115.0);

    datum0.showValue();
    pi -> showValue();
    (pi + 1) -> showValue();
    sta0.showValue();
    datum0.showPcs();        //_pcs is in private.   Output: 12.
    cout << "---------------" << endl;
    for(int i = 0; i < 10; i++)
    {
        arr[i] = new Data(11.0);
        arr[i] -> showValue();
    }
    arr[9] -> showPcs();//Output: 22.



    delete pi;


}

