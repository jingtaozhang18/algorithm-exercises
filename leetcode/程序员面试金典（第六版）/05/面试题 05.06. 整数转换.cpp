// https://leetcode-cn.com/problems/convert-integer-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int convertInteger(int A, int B) {
        int ans=0, i;
        for(i=0;i<32;++i) ans+=( (A&(1<<i)) ^ (B&(1<<i)) )?1:0;
        return ans;
    }
};
