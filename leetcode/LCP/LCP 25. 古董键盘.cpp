// https://leetcode-cn.com/problems/Uh984O/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int mod=1e9+7;
    long long m(long long a, long long b){ // 大数相乘
        long long res=0, temp=a;
        while(b){
            if(b%2) res+=temp;
            b>>=1;
            temp<<=1;
            temp%=mod;
            res%=mod;
        }
        return res;
    }

    int c(int m, int n) { // C(m, n)
        int ans=1, k=1;
        while(k<=n){
            ans=(ans*(m-k+1))/k;
            ++k;
        }
        return ans;
    }

    int keyboard(int k, int n) {
        // dp[i][j] 一共按了i次，前j个键的方法数
        // 极限操作，vector的效率会导致超时
        // vector<vector<int>> dp(n+1, vector<int>(27, 0));
        long long dp[n+1][27];
        memset(dp, 0, sizeof(dp));
        int i, j, x;
        for(i=0;i<=26;++i) dp[0][i]=1; // 按0次，默认都是1
        for(i=1;i<=n;++i){
            for(j=1;j<=26;++j){
                for(x=0;x<=min(i, k);++x){
                    if(x+(j-1)*k<i) continue; // 前面的按键次数的最小值
                    dp[i][j] += m(c(i, x), dp[i-x][j-1]);
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[n][26];
    }
};