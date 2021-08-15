// https://leetcode-cn.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i, j, k, m=nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans(m);
        i=0, j=m-1, k=0;
        while(i<j){
            ans[k++]=nums[i++];
            if(i<j) ans[k++]=nums[j--];
        }
        ans[k]=nums[i];
        return ans;
    }
};