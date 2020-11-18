// https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jgo(int base, int n, int k, int& index, int& ans){
        int i,t;
        base*=10;
        for(i=0;i<10;++i){
            t=base+i;
            if(t&&t<=n){
                index++;
                if(index==k) {ans=t; return true;}
                if(jgo(t, n, k, index, ans)) return true;
            }
        }
        return false;
    }
    int findKthNumber(int n, int k) {
        int index=0, ans=-1;
        jgo(0,n,k,index,ans);
        return ans;
    }
};