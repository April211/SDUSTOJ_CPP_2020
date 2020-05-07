#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double p, w, m;
    double ans;

    scanf("%lf %lf %lf", &p, &w, &m);
    if(m <= 500)
    {
        ans = p*w*m;
    }
    else if(m <= 1000)
    {
        ans = p*w*500.0 + 0.95*p*w*(m - 500.0);
    }
    else if(m <= 2000)
    {
        ans = p*w*500.0 + 0.95*p*w*500.0 + 0.9*p*w*(m - 1000.0);
    }
    else
    {
        ans = p*w*500.0 + 0.95*p*w*500.0 + 0.9*p*w*1000.0 + 0.88*p*w*(m - 2000.0);

    }

    printf("%.2lf", ans);


    return 0;
}

// Problem D: 运费计算
// Time Limit: 1 Sec  Memory Limit: 16 MB
// Submit: 1182  Solved: 687
// [Submit][Status]
// Description
// 运输公司替客户运送货物并收取运费。基本运费为每吨每公里价格，总运费按照运输里程分段打折，计算方法如下：500公里以内部分不打折，501～1000公里部分打九五折，1001～2000公里部分打九折，超过2000公里部分打八八折。
// Input
// 输入三个数字，分别是基本运费p、货物重量w吨、总里程m公里。
// Output
// 输出总运费，精确到小数点后2位。
// Sample Input
// 4.7 29 2008
// Sample Output
// 256522.05
// HINT
// Append Code
