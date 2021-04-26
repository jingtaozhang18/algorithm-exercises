// https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jgo(vector<int>& weights, int D, int C){ // 判断载重为C的船是否可行
        int i, n=weights.size(), ans=0, cap=0;
        for(i=0;i<n;++i){
            if(cap>=weights[i]) cap-=weights[i];
            else{
                if(weights[i]>C) return false;
                cap=C-weights[i], ++ans;
            }
        }
        return ans<=D;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int left=0, right=0, mid;
        for(auto &e:weights) right+=e;
        while(left<=right){
            mid=left+(right-left)/2;
            if(!jgo(weights, D, mid)) left=mid+1;
            else right=mid-1;
        }
        return left;
    }
};