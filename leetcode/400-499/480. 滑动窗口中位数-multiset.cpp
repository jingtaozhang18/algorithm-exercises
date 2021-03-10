// https://leetcode-cn.com/problems/sliding-window-median/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<double> st; // 使用double，否则会出现数组越界
        int i, n=nums.size();
        for(i=0;i<n;++i){
            st.insert(nums[i]);
            if(i>=k-1){
                auto mid=st.begin();
                advance(mid, k / 2);
                ans.push_back((*mid + *prev(mid, (1 - k % 2))) / 2);
                st.erase(st.find(nums[i-k+1]));
            }
        }
        return ans;
    }
};