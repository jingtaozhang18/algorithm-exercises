// https://leetcode-cn.com/problems/set-mismatch/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i, m=nums.size(), a, b;
        for(i=0;i<m;++i){
            while(i+1!=nums[i]){
                if(nums[nums[i]-1]!=nums[i]) swap(nums[nums[i]-1], nums[i]);
                else {a=nums[i]; break;}
            }
        }
        for(i=0;i<m;++i){
            if(i+1!=nums[i]) {b=i+1; break;}
        }
        return vector<int>{a, b};
    }
};