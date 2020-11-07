// https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        // 空间压缩
        vector<vector<int>> dp(6*n+2, vector<int>(2, 0)); // [i][j]第j个骰子投完后，和为i出现的次数
        vector<double> ans(5*n+1, 0);
        int i,j,k;
        for(i=1;i<=6;++i)dp[i][0]=1; // 初始化
        for(j=1;j<n;++j){ // 6个骰子依次
            // 错误点：清理痕迹
            for(i=0;i<6*n+2;++i) dp[i][j%2]=0;
            for(i=1;i<=6;++i){
                for(k=j;dp[k][(j+1)%2];++k){ 
                    dp[k+i][j%2]+=dp[k][(j+1)%2];
                }
            }
        }
        int sum=0;
        for(i=n;i<=6*n;++i) sum+=dp[i][(n+1)%2];
        for(i=n;i<=6*n;++i) ans[i-n]=(double)dp[i][(n+1)%2]/sum;
        return ans;
    }
};