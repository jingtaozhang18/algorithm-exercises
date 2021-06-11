// https://leetcode-cn.com/problems/perfect-squares/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> arr;
        int i=1, j, k, m;
        while(i*i<=n) {arr.push_back(i*i); i+=1;}
        m=arr.size();
        cout<<m<<endl;
        int dp[m+1][n+1];
        for(i=0;i<=m;++i) for(j=0;j<=n;++j) dp[i][j]=(j==0?0:n); // 需要的数量是最大的
        for(i=0;i<m;++i){ // 第i个值之前的进行拼凑
            for(j=1;j<=n;++j){
                for(k=0;k*arr[i]<=j;++k){ // 用k个arr[i];
                    dp[i+1][j]=min(dp[i+1][j], dp[i][j-k*arr[i]]+k);
                }
            }
        }
        return dp[m][n];
    }
};
