// 详细描述
// 将整数转换成千分位表示法。

// 转换规则：从右至左，每三位数字与前一个数字之间插入一个半角逗号","。

// 如：1234567 -> "1,234,567"

// 注意：不允许使用标准库中任何可以直接将整数转换为千分位表示法的函数。

// 其他
// 时间限制: 1000ms

// 内存限制: 256.0MB


#include<bits/stdc++.h>
using namespace std;

int main(void){
    string a;
    cin>>a;
    int m=a.size();
    int x=m/3-(m%3==0?1:0), i, j, k=0, n=m+x;
    string ans(n, ',');
    for(j=n-1,i=m-1,k=0;i>=0;++k,--i){
        ans[j--]=a[i];
        if(k%3==2) --j;
    }
    cout<<ans<<endl;
    return 0;
}