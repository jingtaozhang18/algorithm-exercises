// https://leetcode-cn.com/problems/ways-to-split-array-into-three-subarrays/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jfind(vector<long long>& nums, int left, int right, long long tar){ // [left, right] 查找大于等于tar的第一个数
      int mid;
      while(left<=right){
        mid=left+(right-left)/2;
        if(tar<=nums[mid]) right=mid-1;
        else left=mid+1;
      }
      return left;
    }
    int jfind2(vector<long long>& nums, int left, int right, long long tar){ // [left, right] 查找小于等于2*tar的第一个数
      int mid;
      while(left<=right){
        mid=left+(right-left)/2;
        if(tar<2*nums[mid]) right=mid-1;
        else left=mid+1;
      }
      return right;
    }
    int waysToSplit(vector<int>& nums) {
      int i,j_min,j_max,size=nums.size(),ans=0,m=1e9+7;
      vector<long long> acc;
      acc.push_back(0);
      for(auto e:nums) acc.push_back(acc.back()+e);
      for(i=1;i<size-1;++i){
        j_min=jfind(acc, i+1, size-1, 2*acc[i]);
        if(j_min>size-1) break;
        j_max=jfind2(acc, i+1, size-1, acc[size]+acc[i]);
        if(j_max<j_min) continue;
        ans+=(j_max-j_min+1), ans%=m;
      }
      return ans;
    }
};