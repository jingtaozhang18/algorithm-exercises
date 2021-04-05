// https://leetcode-cn.com/problems/p0NxJO/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicTower(vector<int>& nums) {
        long long acc;
        int i, ans, n=nums.size();
        for(auto &a:nums) acc+=a;
        if(acc<0) return -1;
        priority_queue<int, vector<int>, less<int>> que;
        acc=1, ans=0;
        for(i=0;i<n;++i){
            if(nums[i]>=0) acc+=nums[i];
            else{
                que.push(-nums[i]);
                acc+=nums[i];
                while(acc<=0){
                    // cout<<"pop:"<<que.top()<<endl;
                    acc+=que.top();
                    que.pop();
                    ans++;
                }
            }
            // cout<<"acc:"<<acc<<endl;
        }
        return ans;
    }
};