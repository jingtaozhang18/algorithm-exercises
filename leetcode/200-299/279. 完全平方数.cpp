// https://leetcode-cn.com/problems/perfect-squares/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> arr;
        int i=1, j, k, m;
        while(i*i<=n) {arr.push_back(i*i); i+=1;}
        if(i*i==n) return 1;
        m=arr.size();
        int dp[n+1]; // dp[i] 拼成i需要的最少数量
        for(j=0;j<=n;++j) dp[j]=j;
        for(auto &e:arr){
            for(i=e;i<=n;++i){ // 可以使用的范围
                dp[i]=min(dp[i], dp[i-i/e*e]+i/e); // 贪心，直接使用最多数量
            }
        }
        return dp[n];
    }
};
