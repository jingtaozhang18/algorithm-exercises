// https://leetcode-cn.com/problems/number-of-1-bits/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n){
          ans++;
          n = n&(n-1);
        }
        return ans;
    }
};