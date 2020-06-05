#include<iostream>
#include<string> 
using namespace std;
int main()
{
int arr[100];
int temp;
int count=0;
char c;
while(((cin>>temp).get(c)))
{
     
    arr[count]=temp;
    if(c=='\n')
        break;
    count++;
    if(count>=100)
        break;
}
for(int i=0;i<=count;i++)
    cout<<arr[i];
system("pause");
return 0;
 
}