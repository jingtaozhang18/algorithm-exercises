// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, j=1, k=1, n=nums.size();
        for(;i<n;++i){
            if(nums[i-1]!=nums[i]) k=1;
            else ++k;
            if(k<=2){
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};