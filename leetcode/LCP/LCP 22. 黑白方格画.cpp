// https://leetcode-cn.com/problems/ccw6C7/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(int n, int a) { // 计算n个数中取a个的方法
        if(a==0||a==n) return 1;
        int ans=1,i;
        for(i=n;i>(n-a);--i) ans*=i;
        for(i=a;i>1;--i) ans/=i;
        return ans;
    }
    int paintingPlan(int n, int k) {
        if(n*n==k) return 1;
        int a,b,j,ans=0;
        for(b=0;b<=n&&n*b<=k;++b){
            j=n!=b?(k-n*b)%(n-b):0;
            if(j==0){
                a=n==b?0:(k-n*b)/(n-b);
                j=jgo(n,a)*jgo(n,b);
                cout<<a<<" "<<b<<": "<<j<<endl;
                ans+=j;
            }
        }
        return ans;
    }
};