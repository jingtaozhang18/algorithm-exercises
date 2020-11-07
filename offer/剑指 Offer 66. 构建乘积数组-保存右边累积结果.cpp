// https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> ans(a.size());
        if(!a.size()) return ans;
        vector<int> t(a);
        int i,j,k=1;
        for(i=a.size()-2;i>0;--i) t[i]*=t[i+1];
        for(i=0;i<a.size();++i){
            if(i<a.size()-1) ans[i]=k*t[i+1];
            else ans[i]=k;
            k*=a[i];
        }
        return ans;
    }
};