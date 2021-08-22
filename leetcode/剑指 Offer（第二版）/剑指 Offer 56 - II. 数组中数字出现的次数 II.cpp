// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
#include<bits/stdc++.h>
using namespace std;

// 状态转移
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twos=0, i;
        for(i=0;i<nums.size();++i){
            twos = ~ones&nums[i]^twos;
            ones = ~twos&nums[i]^ones;
        }
        return twos;
    }
};