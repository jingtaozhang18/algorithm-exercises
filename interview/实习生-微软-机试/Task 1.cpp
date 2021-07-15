// 一个数组长度为[1...100,000], 取值为[1...4]
// 选择一个数k，让数组中所有元素k的距离之和最小，输出最小值

// 回忆的答案，不一定准确
#include<bits/stdc++.h>
using namespace std;

// 暴力枚举
int solution(vector<int>& A){
    int ans=INT_MAX, n=A.size(), i, k, acc;
    for(k=1;k<=4;++k){
        for(acc=0, i=0;i<n;++i){
            acc+=abs(A[i]-k);
        }
        ans=min(ans, acc);
    }
    return ans;
}