// https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int ans=0, i, t=0, size=A.size();
        for(i=0;i<size;++i){
            if(i>=K&&A[i-K]>=2){
                t ^= 1; // 之前翻转过，到该位置已经失效了， 取消该位置翻转带来的影响
            }
            if(A[i] == t){ // 需要翻转
                if(i+K>size) return -1;
                ++ans;
                t ^= 1; // 当前范围翻转
                A[i] += 2;
            }
        }
        return ans;
    }
};