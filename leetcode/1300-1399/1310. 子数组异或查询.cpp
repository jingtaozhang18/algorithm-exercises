// https://leetcode-cn.com/problems/xor-queries-of-a-subarray/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size(), i, m=queries.size();
        vector<int> acc(n+1);
        for(i=0;i<n;++i) acc[i+1]=arr[i]^acc[i];
        vector<int> ans(m);
        for(i=0;i<m;++i) ans[i]=acc[queries[i][1]+1]^acc[queries[i][0]];
        return ans;
    }
};