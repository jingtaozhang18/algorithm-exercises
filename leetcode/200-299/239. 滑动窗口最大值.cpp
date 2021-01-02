// https://leetcode-cn.com/problems/sliding-window-maximum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      deque<int> que;
      vector<int> ans;
      int i;
      for(i=0;i<nums.size();++i)
      {
        while(!que.empty()&&que.back()<nums[i]) // 保证队尾元素如果存在大于当前元素
        {
          que.pop_back();
        }
        que.push_back(nums[i]); // 插入到队尾
        if(i>=k-1) // 滑动窗口生成了
        {
          ans.push_back(que.front());
          if(nums[i-k+1]==que.front()) // 判断滑出窗口的值是不是当前的最大值
          {
            que.pop_front();
          }
        }
      }
      return ans;
    }
};