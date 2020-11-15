// https://leetcode-cn.com/problems/count-of-range-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size()==0) return false;
        int i,j,ans=0;
        long long t; // 错误点 int 相加越界
        vector<long long> tnums(nums.begin(), nums.end());
        for(i=0,t=0;i<tnums.size();++i) t+=nums[i], tnums[i]=t;
        for(i=0;i<tnums.size();++i){
            for(j=i;j<tnums.size();++j){
                t=i==0?tnums[j]:(tnums[j]-tnums[i-1]);
                if(t>=lower&&t<=upper) {++ans;}
            }
        }
        return ans;
    }
};