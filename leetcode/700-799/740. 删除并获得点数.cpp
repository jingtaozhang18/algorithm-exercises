// https://leetcode-cn.com/problems/delete-and-earn/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        map<int, int>::iterator p, q;
        for(auto &e:nums) mp[e]++;
        int n=mp.size(), i, j;
        int dp[n+1][2]; // [i][0]不要mp中第i个元素的最大值
        dp[0][0]=dp[0][1]=0;
        for(p=mp.begin(), q=mp.end(), i=0;i<n;q=p, ++p, ++i){
            if(q!=mp.end()&&p->first-q->first==1){
                dp[i+1][0]=max(dp[i][0], dp[i][1]);
                dp[i+1][1]=dp[i][0]+p->first*p->second;
            }else{
                dp[i+1][0]=max(dp[i][0], dp[i][1]);
                dp[i+1][1]=dp[i+1][0]+p->first*p->second;
            }
        }
        return max(dp[n][0], dp[n][1]);
    }
};