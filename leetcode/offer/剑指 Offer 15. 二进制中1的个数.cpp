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

// again
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n) {
          ans++;
          n = (n-1)&n; // n-1之后，n中最后一个1变成0, 该位置右边的位变成1
        }
        return ans;
    }
};

// 复习
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n) ans++, n&=(n-1);
        return ans;
    }
};