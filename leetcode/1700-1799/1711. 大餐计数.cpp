// https://leetcode-cn.com/problems/count-good-meals/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<long, int> mp;
        long x, i, ans=0, m=1e9+7; m*=2; // 注意取模的计算
        for(auto &e:deliciousness) mp[e]++;
        for(auto &p:mp){
            for(i=0;i<32;++i){
                x=1<<i;
                auto op=mp.find(x-p.first);
                if(op!=mp.end()){
                    if(op->first==p.first){
                        ans+=((p.second%m)*((p.second-1)%m));
                    }else{
                        ans+=(p.second%m)*(op->second%m);
                    }
                    ans%=m;
                }
            }
        }
        return ans/2;
    }
};
