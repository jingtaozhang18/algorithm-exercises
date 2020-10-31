// https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        vector<int> arr(n+1, 0);
        arr[1]=1,arr[2]=2,arr[3]=3;
        int i,j;
        for(i=4;i<=n;++i){
            for(j=1;j<i;++j)
                arr[i]=max(arr[i],arr[j]*arr[i-j]);
        }
        return arr[n];
    }
};