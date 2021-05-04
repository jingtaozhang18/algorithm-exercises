// https://leetcode-cn.com/problems/first-missing-positive/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size(), i, k;
        // 长度为n，最小没有出现的正数最大也是n+1, 如此就处理掉了非正数
        for(i=0;i<n;++i) if(nums[i]<=0) nums[i]=n+1;
        for(i=0;i<n;++i) { // 标记
            k=abs(nums[i]);
            if(k>0&&k<=n) if(nums[k-1]>0)nums[k-1]*=-1;
        }
        for(i=0;i<n;++i){
            if(nums[i]>=0) return i+1;
        }
        return i+1;
    }
};