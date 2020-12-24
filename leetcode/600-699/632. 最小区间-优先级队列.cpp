// https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/
#include<bits/stdc++.h>
using namespace std;

// TODO 不会用
// struct cmp{
//   vector<vector<int>> *nums;
//   vector<int> *next;
//   cmp(vector<vector<int>> *tnums, vector<int> *tnext){
//     nums=tnums, next=tnext;
//   }
//   bool operator()(const int i, const int j) const{
//     return (*nums)[i][(*next)[i]]<(*nums)[j][(*next)[j]];
//   }
// };

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
      int i,size=nums.size(),max_val=INT_MIN,rg_l=-1e5, rg_r=1e5;
      vector<int> next(size);
      auto cmp = [&](const int& u, const int& v) { // 最小优先级队列 封闭函数定义
          return nums[u][next[u]] > nums[v][next[v]];
      };
      priority_queue<int, vector<int>, decltype(cmp)> que(cmp);
      for(i=0;i<size;++i){que.push(i);max_val=max(max_val, nums[i][0]);} // 计算最大值
      while(true){
        int min_idx=que.top(); que.pop();
        int min_val=nums[min_idx][next[min_idx]];
        if(max_val-min_val<rg_r-rg_l) rg_l=min_val, rg_r=max_val;
        // next[min_idx]++;
        // if(next[min_idx]==nums[min_idx].size()) break;
        // 小的优化，跳过重复的元素
        do{next[min_idx]++;}while(next[min_idx]<nums[min_idx].size()&&nums[min_idx][next[min_idx]]==nums[min_idx][next[min_idx]-1]);
        if(next[min_idx]==nums[min_idx].size()) break;
        max_val=max(max_val, nums[min_idx][next[min_idx]]);
        que.push(min_idx);
      }
      return vector<int>{rg_l, rg_r};
    }
};