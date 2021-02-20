// https://leetcode-cn.com/problems/degree-of-an-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> pre;
        unordered_map<int, int> post;
        unordered_map<int, int> freq;
        int i, size=nums.size(), f=0, ans=0;
        for(i=0;i<size;++i){
            if(pre.find(nums[i])==pre.end()) pre[nums[i]]=i;
            post[nums[i]]=i;
            freq[nums[i]]++;
        }
        for(auto p:freq){
            if(p.second>f){
                f=p.second;
                ans=post[p.first]-pre[p.first];
            }else if(p.second==f){
                ans=min(ans, post[p.first]-pre[p.first]);
            }
        }
        return ++ans;
    }
};