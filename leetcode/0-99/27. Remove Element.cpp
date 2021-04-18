// https://leetcode-cn.com/problems/remove-element/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, j, n=nums.size();
        for(i=0, j=0;i<n;++i){
            if(nums[i]==val) continue;
            nums[j++]=nums[i];
        }
        return j;
    }
};