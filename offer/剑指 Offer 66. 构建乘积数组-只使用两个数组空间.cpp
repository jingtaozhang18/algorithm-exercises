// https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> ans(a.size());
        if(a.size()==0) return ans;
        ans[0]=1;
        int i,t=1;
        for(i=1;i<a.size();++i) ans[i]=ans[i-1]*a[i-1];
        for(i=a.size()-2;i>=0;--i) t*=a[i+1], ans[i]*=t;
        return ans;
    }
};