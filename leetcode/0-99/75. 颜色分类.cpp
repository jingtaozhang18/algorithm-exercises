// https://leetcode-cn.com/problems/sort-colors/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=-1, b=nums.size(), i;
        for(i=0;i<b;++i){
            if(nums[i]==0) swap(nums[++a], nums[i]);
            else if(nums[i]==2) {
                swap(nums[--b], nums[i]);
                --i;
            }
        }
    }
};