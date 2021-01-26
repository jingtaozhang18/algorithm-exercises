// https://leetcode-cn.com/problems/reverse-integer/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
      int a=INT_MAX/10, b=INT_MAX-a*10, c=INT_MIN/10, d=INT_MIN-c*10, ans=0, t;
      while(x){
        t=x%10, x/=10;
        if(ans>a) return 0;
        else if(ans==a&&t>b) return 0;
        else if(ans<c) return 0;
        else if(ans==c&&t<d) return 0;
        ans*=10, ans+=t;
      }
      return ans;
    }
};