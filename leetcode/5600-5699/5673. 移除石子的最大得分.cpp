// https://leetcode-cn.com/problems/maximum-score-from-removing-stones/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> arr{a,b,c};
        sort(arr.begin(), arr.end());
        int ans=0, t, x;
        x=arr[0]+arr[1];
        t=min(x, arr[2]);
        ans+=t;
        x-=t;
        x/=2;
        ans+=min({arr[0], arr[1], x});
        return ans;
    }
};