// https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jcan(vector<int>& bloomDay, int k, int d, int m){ // 第d天，可以制作的数量
        int i=0, n=bloomDay.size(), x;
        for(x=i=0;i<n;++i){
            if(bloomDay[i]<=d){
                ++x;
                if(x==k) {
                    --m, x=0;
                    if(m==0){
                        return true;
                    }
                }
            }else x=0;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left=0, right=1e9+1, mid;
        while(left<=right){
            mid=(left+right)/2;
            if(jcan(bloomDay, k, mid, m)) right=mid-1;
            else left=mid+1;
        }
        return jcan(bloomDay, k, left, m)?left:-1;
    }
};