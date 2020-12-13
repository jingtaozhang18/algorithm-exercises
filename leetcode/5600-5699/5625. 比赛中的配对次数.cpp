// https://leetcode-cn.com/problems/count-of-matches-in-tournament/
// 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int ans=0,t;
        while(n>1){
            t=n>>1, ans+=t, n-=t;
        }
        return ans;
    }
};