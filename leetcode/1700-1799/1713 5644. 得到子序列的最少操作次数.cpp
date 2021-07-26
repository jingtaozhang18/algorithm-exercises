// https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        int i, size=target.size(),left,right,mid;
        for(i=0;i<size;++i) mp[target[i]]=i;
        i=-1;
        vector<int> dp(size, INT_MAX);
        for(auto e:arr){
            if(mp.find(e)!=mp.end()){
                e=mp[e];
                left=0, right=i;
                while(left<=right) { // 在数组中找到大于e的第一个数
                    mid=left+(right-left)/2;
                    if(dp[mid]>=e) right=mid-1;
                    else left=mid+1;
                }
                dp[left]=min(dp[left], e);
                i=max(i,left);
            }
        }
        return size-i-1;
    }
};

// 复习
class Solution {
public:
    int jfind(vector<int>&arr, int tar){ // 找到大于等于tar的第一个元素
        int left=0, right=arr.size()-1, mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(arr[mid]>=tar) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        int i, k;
        for(i=0;i<target.size();++i) mp[target[i]]=i;
        vector<int> narr;
        for(i=0;i<arr.size();++i){
            auto p=mp.find(arr[i]);
            if(p!=mp.end()){
                narr.push_back(p->second);
            }
        }
        vector<int> dp;
        for(auto &e:narr){
            k=jfind(dp, e);
            if(k==dp.size()) dp.push_back(e);
            else dp[k]=e;
        }
        return target.size()-dp.size();
    }
};
