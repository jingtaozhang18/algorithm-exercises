// https://leetcode-cn.com/problems/maximum-element-after-decreasing-and-rearranging/
#include<bits/stdc++.h>
using namespace std;

// 排序 + 贪心
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i, m=arr.size();
        arr[0]=1;
        for(i=1;i<m;++i) arr[i]=min(arr[i], arr[i-1]+1);
        return arr[m-1];
    }
};
