// https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/solution/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int i,a;
        for(i=0;i<nums.size();++i){
            a=abs(nums[i]); // i上面放置i+1的元素
            while(a!=i+1){ // 元素a没有坐好
                // 使用负数标记已经遇到过的数字
                if(abs(nums[a-1])!=a) nums[i]=nums[a-1], nums[a-1]=-a, a=abs(nums[i]);
                else {if(nums[i]>0) {ans.push_back(nums[i]); nums[i]=-nums[i];} break;}
            }
        }
        return ans;
    }
};