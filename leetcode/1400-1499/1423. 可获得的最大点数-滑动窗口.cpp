// https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i, acc=0, sum=0, ans=INT_MAX, size=cardPoints.size();
        k=size-k;
        for(i=0;i<=size;++i){ // 错误点： 采用先判断长度的做法，相当于[x, i)的范围，需要遍历到size的位置上
            if(i>=k) ans=min(ans, acc), acc-=cardPoints[i-k];
            if(i<size) acc+=cardPoints[i], sum+=cardPoints[i]; // 错误点： 对应的需要添加判断逻辑
        }
        return sum-ans;
    }
};