// https://leetcode-cn.com/problems/find-majority-element-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m=nums.size();
        if(m==0) return -1;
        int val, times=0;
        for(auto &e:nums){
            if(val==e) times++;
            else times--;
            if(times<=0) val=e, times=1;
        }
        times=0;
        for(auto &e:nums) times+=e==val?1:0;
        return times*2>m?val:-1;
    }
};
