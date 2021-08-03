// https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr(nums);
        sort(arr.begin(), arr.end());
        int i, j, ans=0;
        for(i=0;i<arr.size();++i){
            if(arr[i]==nums[i]) ans++;
            else break;
        }
        for(j=arr.size()-1;j>i;--j){
            if(arr[j]==nums[j]) ans++;
            else break;
        }
        return arr.size()-ans;
    }
};
