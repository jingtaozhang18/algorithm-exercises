// https://leetcode-cn.com/problems/building-boxes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(int n) {
      int level=1, sum=0, ans;
      while(sum<n) sum+=(((level+1)*level)>>1), ++level; // 构建一个满堆
      --level, ans=((level+1)*level)>>1;
      while(sum-n>=level) sum-=level, --level, --ans; // 减去多余的成分
      return ans;
    }
};
