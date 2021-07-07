// https://leetcode-cn.com/problems/count-good-meals/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> mp;
        int ans=0, sum, i, m=1e9+7;
        for(auto e:deliciousness){
            for(sum=1, i=0;i<21;++i){
                if(mp.find(sum-e)!=mp.end()){
                    ans+=mp[sum-e], ans%=m;
                }
                sum<<=1;
            }
            mp[e]++;
        }
        return ans;
    }
};