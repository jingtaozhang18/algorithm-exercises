// https://leetcode-cn.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int n=min(steps+1, arrLen), i, j, mod=1e9+7;
        int arr[2][n];
        for(i=1;i<n;++i) arr[0][i]=arr[1][i]=0;
        arr[0][0]=1;
        for(i=0;i<steps;++i){
            for(j=0;j<n;++j){
                arr[(i+1)%2][j]=arr[i%2][j];
                if(j) arr[(i+1)%2][j]+=arr[i%2][j-1], arr[(i+1)%2][j]%=mod;
                if(j<n-1) arr[(i+1)%2][j]+=arr[i%2][j+1], arr[(i+1)%2][j]%=mod;
            }
        }
        return arr[steps%2][0];
    }
};