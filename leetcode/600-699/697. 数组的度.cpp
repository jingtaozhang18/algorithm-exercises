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

// 使用tuple之后没有明显的速度提升
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, tuple<int, int, int>> map;
        int i, size=nums.size(), f=0, ans=0,a,b,c;
        for(i=0;i<size;++i){
            if(map.find(nums[i])==map.end()) {
                map[nums[i]] = {i, i, 1};
            }else{
                get<1>(map[nums[i]]) = i;
                get<2>(map[nums[i]])++;
            }
        }
        for(auto p:map){
            tie(a,b,c) = p.second;
            if(c>f){
                f=c;
                ans=b-a;
            }else if(c==f){
                ans=min(ans, b-a);
            }
        }
        return ++ans;
    }
};