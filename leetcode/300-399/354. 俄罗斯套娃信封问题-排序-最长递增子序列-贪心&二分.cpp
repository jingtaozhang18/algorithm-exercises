// https://leetcode-cn.com/problems/russian-doll-envelopes/
#include<bits/stdc++.h>
using namespace std;

struct evl{
    int x,y;
    evl(int x, int y):x(x),y(y){};
    bool operator<(const evl& other)const{
        if(x<other.x) return true; else if(x>other.x) return false;
        if(y>other.y) return true;
        return false;
    }
};

class Solution {
public:
    int jgo(vector<int>& nums, int tar){ // 从右向左找到比tar小的第一个数
        int left=0, right=nums.size()-1,center;
        while(left<=right){
            center=(left+right)>>1;
            if(nums[center]>=tar) right=center-1;
            else left=center+1;
        }
        return left;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==0) return 0;
        vector<evl> arr(envelopes.size(), evl(0, 0));
        int i, j, t, ans=1;
        for(i=0;i<envelopes.size();++i) arr[i].x=envelopes[i][0], arr[i].y=envelopes[i][1];
        sort(arr.begin(), arr.end());
        // 对h计算最大递增子序列
        // 贪心 + 二分查找
        vector<int> dp;
        dp.push_back(arr[0].y);
        for(i=1;i<arr.size();++i){
            if(arr[i].y>dp[dp.size()-1]) {dp.push_back(arr[i].y); continue;}
            dp[jgo(dp, arr[i].y)]=arr[i].y; // [1] 找1的情况
        }
        return dp.size();
    }
};