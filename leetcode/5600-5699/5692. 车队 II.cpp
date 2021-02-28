// https://leetcode-cn.com/problems/car-fleet-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int i, size=cars.size(), j;
        double t, p1, p2;
        vector<double> ans(size, -1);
        deque<int> sta;
        int p;
        for(i=size-1;i>=0;--i){  // 没有考虑到车辆会提前减速
            while(sta.size()&&cars[sta.back()][1]>=cars[i][1]){ sta.pop_back(); } // 清理不会发生碰撞的车辆
            if(sta.size()){
                while(true){
                    p=sta.back(), p1=cars[i][0], p2=cars[p][0];  // i, p
                    t=double(p2-p1)/(cars[i][1]-cars[p][1]); // 在前车碰撞减速之前，判断能否与之发生碰撞
                    if(ans[p]>0.00000001&&t>ans[p]-0.00000001){ // 若不能碰撞， 我们就考虑去撞前面的车
                         sta.pop_back();
                    }else {
                        break;
                    };
                }
                ans[i]=t; // 前车不会出现减速的情况
            }
            sta.push_back(i);
        }
        return ans;
    }
};