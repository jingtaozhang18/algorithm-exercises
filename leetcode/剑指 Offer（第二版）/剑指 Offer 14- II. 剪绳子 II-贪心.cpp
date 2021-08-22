// https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        long long ans=1;
        int n3=n/3;
        if((n-n3*3)%2) n3-=1;
        int n2=(n-n3*3)/2;
        while(n3--) ans=(ans*3)%1000000007;
        while(n2--) ans=(ans*2)%1000000007;
        return ans;
    }
};

// again
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