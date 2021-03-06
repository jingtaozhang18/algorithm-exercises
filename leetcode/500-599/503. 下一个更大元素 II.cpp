// https://leetcode-cn.com/problems/next-greater-element-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int i, n=nums.size(), x;
        stack<int> sta; // 
        vector<int> ans(n, -1);
        for(i=0;i<2*n;++i){
            while(sta.size()&&nums[sta.top()]<nums[i%n]){
                x=sta.top();
                sta.pop();
                if(ans[x]==-1){ // 多余：其实是没有必要的
                    ans[x]=nums[i%n];
                }
            }
            sta.push(i%n);
        }
        return ans;
    }
};