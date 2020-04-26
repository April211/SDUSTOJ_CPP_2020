#include <bits/stdc++.h>
using namespace std;

class Data
{
public:
    Data():$x(0){cout << "Data's default constructor." << endl;}
    Data(int x):$x(x){cout << "Data " << $x << " is created." << endl;}
    ~Data(){cout << "Data " << $x << " is erased." << endl;}
    int getValue()const;
    void setValues(int);
private:
    int $x;
};
inline int Data::getValue()const{return $x;}
inline void Data::setValues(int temp){$x = temp;}

class DataArray
{
public:
    DataArray(){cout << "DataArray's default constructor." << endl;}
    void setValues(int d[10]);
    int getSum()const;
    ~DataArray(){cout << "DataArray's deconstructor." << endl;}
private:
    Data dt[10];
};

void DataArray::setValues(int d[10])
{
    for(int i = 0; i < 10; i++)
    {
        dt[i].setValues(d[i]);
    }
}

int DataArray::getSum()const
{
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        sum = sum + dt[i].getValue();
    }
    return sum;
}


int main()
{
    DataArray dataArray;
    Data *aData;
    int data[10], tmp;
    int i;
    for (i = 0; i < 10; i++){
        cin>>data[i];
    }
    dataArray.setValues(data);
    cout<<"Sum is "<<dataArray.getSum()<<endl;

    cin>>tmp;
    aData = new Data(tmp);
    cout<<"aData = "<<aData->getValue()<<endl;
    delete aData;
    return 0;
}


//Problem A: ��ĳ����飨IV��
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 3740  Solved: 2328
//[Submit][Status]
//Description
//����һ����Data��ֻ��һ��int���͵����Ժ����·�����
//
//1.   ȱʡ���캯���������Գ�ʼ��Ϊ0�������"Data's default constructor."��
//
//2.  ���ι��캯���������Գ�ʼ��Ϊָ�������������"Data # is created."�����С�#��������ֵ��
//
//3. ���������������"Data # is erased."�����С�#��������ֵ��
//
//4.   int getValue()�����������ֵ��
//
//5.    void setValue(int)������������ֵ��
//
//����һ����Data�Ķ�����ɵ�������DataArray��������
//
//1. ��10��Data��Ķ�����ɵĶ������顣
//
//2. ȱʡ���캯�����������κβ����������һ��"DataArray's default constructor."��
//
//3. void setValues(int d[10])��������10��Data�Ķ��������ֵ�ֱ�Ϊ����d��10��ֵ��
//
//4. int getSum()������10��Data��������ֵ�ĺ͡�
//
//5. ���������������һ��"DataArray's deconstructor."��
//
//Input
//����Ϊ11��int���ͷ�Χ�ڵ�������
//
//Output
//������~~~
//
//Sample Input
//1 2 3 4 5 6 7 8 9 10 100
//Sample Output
//Data's default constructor.
//Data's default constructor.
//Data's default constructor.
//Data's default constructor.
//Data's default constructor.
//Data's default constructor.
//Data's default constructor.
//Data's default constructor.
//Data's default constructor.
//Data's default constructor.
//DataArray's default constructor.
//Sum is 55
//Data 100 is created.
//aData = 100
//Data 100 is erased.
//DataArray's deconstructor.
//Data 10 is erased.
//Data 9 is erased.
//Data 8 is erased.
//Data 7 is erased.
//Data 6 is erased.
//Data 5 is erased.
//Data 4 is erased.
//Data 3 is erased.
//Data 2 is erased.
//Data 1 is erased.






