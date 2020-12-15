// https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n){
            ans+=1;
            n=n&(n-1);
        }
        return ans;
    }
};