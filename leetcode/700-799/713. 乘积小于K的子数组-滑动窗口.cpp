// https://leetcode-cn.com/problems/subarray-product-less-than-k/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int acc=1, ans=0, left=0, right=0, size=nums.size();
        while(right<size){
            acc*=nums[right++];
            while(left<right&&acc>=k) acc/=nums[left++];
            if(acc<k) ans+=right-left;
        }
        return ans;
    }
};