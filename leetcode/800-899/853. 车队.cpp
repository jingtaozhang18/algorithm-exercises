// https://leetcode-cn.com/problems/car-fleet/
#include<bits/stdc++.h>
using namespace std;


// 离终点更近的车到达终点的时间比前面最慢的车慢，就会融入到车队中，车队数量就会减少一个
struct car{
    int pos;
    double time;
    car(){};
    car(int pos, double time):pos(pos), time(time){};
    bool operator<(const car &other) const{
        return pos<other.pos;
    }
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int i, size=position.size(), ans=size;
        if(!size) return size;
        vector<car> arr(size);
        for(i=0;i<size;++i){
            arr[i]=car(position[i], double(target-position[i])/speed[i]);
        }
        sort(arr.begin(), arr.end());
        double vmax=arr[size-1].time;
        for(i=arr.size()-2;i>=0;--i){
            if(arr[i].time<=vmax) ans--;
            else vmax=arr[i].time;
        }
        return ans;
    }
};