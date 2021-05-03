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

// 复习，惨不忍睹
class Solution {
public:
    int reverse(int x) {
      // 不要尝试对x乘以-1的操作，容易越界
        int ans=0;
        while(x){
            if(ans>INT_MAX/10||ans<INT_MIN/10) return 0;
            if(ans==INT_MAX/10&&x>INT_MAX-INT_MAX/10) return 0;
            if(ans==INT_MIN/10&&x<INT_MIN-INT_MIN/10) return 0;
            ans*=10, ans+=x%10, x/=10;
        }
        return ans;
    }
};

// -2147483648
// -2147483412
// 1534236469
