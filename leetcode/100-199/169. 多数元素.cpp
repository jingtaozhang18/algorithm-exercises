// https://leetcode-cn.com/problems/majority-element/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int times=1, ans=nums[0], i;
        for(i=1;i<nums.size();++i){
            if(nums[i]==ans) times++;
            else{
                times--;
                if(times==0){
                    ans=nums[i];
                    times=1;
                }
            }
        }
        return ans;
    }
};