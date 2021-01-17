// https://leetcode-cn.com/contest/weekly-contest-224/problems/tuple-with-same-product/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans=0,t;
        int i,j,size=nums.size();
        for(i=0;i<size;++i){
            for(j=i+1;j<size;++j){
                mp[nums[i]*nums[j]]++;
            }
        }
        for(auto p:mp){
            if(p.second>1){
                t=p.second;
                ans=ans+t*(t-1)*4;
            }
        }
        return ans;
    }
};