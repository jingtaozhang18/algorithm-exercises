// https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
      if(n<=3) return n-1;
      int t3=n/3;
      long long left=n%3;
      if(left==1) left+=3, t3--; // 1,3 不如4
      if(left==0) left=1;
      while(t3--){
        left*=3;
        left=left%int(1e9+7);
      }
      return left;
    }
};