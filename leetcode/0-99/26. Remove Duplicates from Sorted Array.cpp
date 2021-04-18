// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j, n=nums.size();
        for(i=j=0;i<n;++i){
            if(i&&nums[i-1]==nums[i]) continue;
            nums[j++]=nums[i];
        }
        return j;
    }
};