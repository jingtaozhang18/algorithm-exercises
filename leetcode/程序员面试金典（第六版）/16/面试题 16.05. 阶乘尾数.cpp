// https://leetcode-cn.com/problems/factorial-zeros-lcci/
#include<bits/stdc++.h>
using namespace std;

// 因子5的数量
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        while(n) ans+=(n/5), n/=5;
        return ans;
    }
};