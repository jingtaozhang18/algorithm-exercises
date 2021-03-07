// https://leetcode-cn.com/problems/minimum-elements-to-add-to-form-a-given-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0; // 错误点，数值边界
        for(auto e:nums) sum+=e;
        long long diff=goal-sum;
        long long ans=abs(diff)/limit;
        if(abs(diff)%limit) ans++;
        return ans;
    }
};