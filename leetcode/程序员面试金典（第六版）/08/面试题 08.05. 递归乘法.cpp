// https://leetcode-cn.com/problems/recursive-mulitply-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int multiply(int A, int B) {
        if(A==0||B==0) return 0;
        int ans=multiply(A, B/2);
        ans+=ans;
        if(B%2) ans+=A;
        return ans;
    }
};