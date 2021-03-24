// https://leetcode-cn.com/problems/132-pattern/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int i,j,k,mivi=-1,size=nums.size(); // mivi 最小值对应的下标
        stack<int> sta; // 栈顶元素最小
        vector<int> arr(size);
        arr[0]=INT_MAX;
        for(i=1;i<size;++i) arr[i]=min(arr[i-1], nums[i-1]); // 计算i位置之前的最小元素
        // 计算i位置右侧比i小数字中的最大值
        for(i=size-1;i>0;--i){
            if(arr[i]>=nums[i]) continue;
            // 向前的最小值不会变小，所以栈顶的小元素可以弹出不再关心
            while(!sta.empty()&&sta.top()<=arr[i]) sta.pop();
            if(!sta.empty()&&sta.top()<nums[i]) return true;
            else sta.push(nums[i]);
        }
        return false;
    }
};

// 复习
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int i, j, n=nums.size();
        vector<int> pre_min(n);
        pre_min[0]=INT_MAX;
        for(i=1;i<n;++i) pre_min[i]=min(pre_min[i-1], nums[i-1]); // pre_min[i] 为i位置之前的最小值
        stack<int> sta;
        for(j=n-1;j>0;--j){
            while(sta.size()&&sta.top()<=pre_min[j]) sta.pop();
            if(sta.size()&&sta.top()<nums[j]) return true;
            else sta.push(nums[j]);
        }
        return false;
    }
};