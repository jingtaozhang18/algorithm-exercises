// https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
#include<bits/stdc++.h>
using namespace std;

// 滑动窗口
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int i=1,j=2,sum=3,k;
        while(j-i>0){
            if(sum==target) {
                vector<int> t(j-i+1);
                for(k=i;k<=j;++k) t[k-i]=k;
                ans.push_back(t);
                sum-=i, i++; // 主动移动
            }else if(sum>target) sum-=i, i++; // 记录sum的变化
            else j++, sum+=j;
        }
        return ans;
    }
};