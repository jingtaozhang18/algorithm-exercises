// https://leetcode-cn.com/problems/best-sightseeing-pair/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int i, ans=INT_MIN, mav=A[0]+0;
        for(i=1;i<A.size();++i){
            ans=max(ans, A[i]-i+mav);
            mav=max(mav, A[i]+i);
        }
        return ans;
    }
};