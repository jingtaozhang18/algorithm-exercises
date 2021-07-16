// https://leetcode-cn.com/problems/maximum-element-after-decreasing-and-rearranging/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int m=arr.size(), i;
        vector<int> record(m+1);
        for(auto e:arr) record[min(e, m)]++;
        int miss=0;
        for(i=1;i<=m;++i){
            if(record[i]==0) miss++;
            else if(miss>0){
                miss-=(record[i]-1);
                miss=max(0, miss); // 取值范围校验
            }
        }
        return m-miss;
    }
};