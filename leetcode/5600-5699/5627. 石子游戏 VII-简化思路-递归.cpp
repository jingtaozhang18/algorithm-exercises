// https://leetcode-cn.com/problems/stone-game-vii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<int>& arr, int i, int j, unordered_map<int, int>& mem){
        int key = i*1000+j;
        if(i==j){return 0;}
        else{
            unordered_map<int, int>::iterator p;
            p=mem.find(key);
            if(p!=mem.end()){
                return p->second;
            }
            int l,r;
            r=jgo(arr, i+1, j, mem); // 右侧 arr[j]-arr[i]
            l=jgo(arr, i, j-1, mem); // 左侧 arr[j-1]-arr[i-1]
            int ans = max(
                arr[j]-arr[i]-r,
                arr[j-1]-arr[i-1]-l);
            mem[key]=ans;
            return ans;
        }
    }
    int stoneGameVII(vector<int>& stones) {
        int a, b;
        vector<int> arr;
        arr.push_back(0);
        for(auto s:stones) arr.push_back(arr.back()+s);
        unordered_map<int, int> mem;
        return jgo(arr, 1, stones.size(), mem);
    }
};