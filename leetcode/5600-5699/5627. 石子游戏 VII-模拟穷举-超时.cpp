// https://leetcode-cn.com/problems/stone-game-vii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(vector<int>& arr, int i, int j, bool a, unordered_map<int, pair<int, int>>& mem, int& resA, int& resB){
        int key = (i*1000+j)*(a?1:-1);
        // cout<<i<<" "<<j<<" "<<a<<" "<<key<<endl;
        if(i==j){
            resA=0,resB=0;
            return;
        }else{
            unordered_map<int, pair<int,int>>::iterator p;
            p=mem.find(key);
            if(p!=mem.end()){
                resA = p->second.first;
                resB = p->second.second;
                return;
            }
            int lra, lrb, rra, rrb;
            jgo(arr, i+1, j, !a, mem, lra, lrb); // 右侧 arr[j]-arr[i]
            jgo(arr, i, j-1, !a, mem, rra, rrb); // 左侧 arr[j-1]-arr[i-1]
            if(a){ // a的游戏主动权
                int chose_l=lra+arr[j]-arr[i]-lrb, chose_r=rra-rrb+arr[j-1]-arr[i-1];
                if(chose_l>chose_r){ // A 希望差距更大
                    mem[key]=make_pair(lra+arr[j]-arr[i], lrb);
                }else{
                    mem[key]=make_pair(rra+arr[j-1]-arr[i-1], rrb);
                }
            }else{
                int chose_l=lra-arr[j]+arr[i]-lrb, chose_r=rra-rrb-arr[j-1]+arr[i-1];
                if(chose_l>chose_r){ // B希望差距更小
                    mem[key]=make_pair(rra, rrb+arr[j-1]-arr[i-1]);
                }else{
                    mem[key]=make_pair(lra, lrb+arr[j]-arr[i]);
                }
            }
            p=mem.find(key);
            resA = p->second.first, resB=p->second.second;
            // cout<<i<<" "<<j<<" "<<a<<": "<<resA<<" "<<resB<<endl;
        }
    }
    int stoneGameVII(vector<int>& stones) {
        int a, b;
        vector<int> arr;
        arr.push_back(0);
        for(auto s:stones) arr.push_back(arr.back()+s);
        unordered_map<int, pair<int,int>> mem;
        jgo(arr, 1, stones.size(), true, mem, a, b);
        // cout << a << " " << b <<endl;
        return a-b;
    }
};