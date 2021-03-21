// https://leetcode-cn.com/contest/weekly-contest-233/problems/maximum-value-at-a-given-index-in-a-bounded-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calc(long long size, long long v){
        long long ans=0;
        if(v>=size) ans=((v+v-size+1)*size)>>1; // 可以一直下降
        else{ // 不能一直下降
            ans=((v+1)*v)>>1;
            ans+=(size-v);
        }
        return ans;
    }
    bool judge(int n, int index, int ans, int maxSum){
        long long minv;
        int sa=index, sb=n-index-1;
        minv=ans+calc(sa, ans-1)+calc(sb, ans-1);
        // cout<<ans<<" "<<(minv<=maxSum)<<endl;
        return minv<=maxSum;
    }
    
    int maxValue(int n, int index, int maxSum) {
        int left=1, right=maxSum, mid;
        while(left<=right){
            mid=(left+right)/2;
            if(judge(n, index, mid, maxSum)) left=mid+1;
            else right=mid-1;
        }
        return right;
    }
};