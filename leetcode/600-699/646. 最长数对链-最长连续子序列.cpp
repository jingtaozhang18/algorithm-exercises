// https://leetcode-cn.com/problems/maximum-length-of-pair-chain/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int i, n=pairs.size(),ans=0,l,c,r;
        vector<int> mem(n+1, INT_MAX);
        sort(pairs.begin(), pairs.end());
        for(i=0;i<n;++i){
            l=1,r=ans;
            while(l<=r){c=(l+r)>>1; if(mem[c]<pairs[i][0]) l=c+1; else r=c-1;}
            ans=max(ans,l), mem[l]=min(mem[l], pairs[i][1]);
        }
        return ans;
    }
};