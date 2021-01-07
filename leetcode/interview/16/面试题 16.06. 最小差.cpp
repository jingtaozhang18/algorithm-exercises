// https://leetcode-cn.com/problems/smallest-difference-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i=0,j=0,m=a.size(),n=b.size();
        long long diff=LONG_MAX, t;
        while(i<m||j<n){
            t=abs((long long)a[i]-(long long)b[j]);
            diff=min(diff, t);
            if(a[i]<b[j]){++i; if(i==m) break;}
            else {++j; if(j==n) break;}
        }
        return diff;
    }
};