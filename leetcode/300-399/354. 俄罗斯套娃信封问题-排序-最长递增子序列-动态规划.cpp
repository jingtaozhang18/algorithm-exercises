// https://leetcode-cn.com/problems/russian-doll-envelopes/
#include<bits/stdc++.h>
using namespace std;

struct evl{
    int x,y;
    evl(int x, int y):x(x),y(y){};
    // x递增，y递减
    bool operator<(const evl& other)const{
        if(x<other.x) return true; else if(x>other.x) return false;
        if(y>other.y) return true;
        return false;
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==0) return 0;
        vector<evl> arr(envelopes.size(), evl(0, 0));
        int i, j, t, ans=1;
        for(i=0;i<envelopes.size();++i) arr[i].x=envelopes[i][0], arr[i].y=envelopes[i][1];
        sort(arr.begin(), arr.end());
        // 对h计算最大递增子序列
        // 动态规划
        vector<int> dp(envelopes.size(), 1);
        for(i=1;i<dp.size();++i){
            for(j=0,t=0;j<i;++j) if(arr[j].y<arr[i].y) t=max(t, dp[j]);
            dp[i]=t+1, ans=max(ans, dp[i]);
        }
        return ans;
    }
};