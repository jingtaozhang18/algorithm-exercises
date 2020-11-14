// https://leetcode-cn.com/problems/the-skyline-problem/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int x,h;
    bool isAdd;
    node(){};
    node(int x, int h, bool isAdd):x(x),h(h),isAdd(isAdd){};
    bool operator<(const node&other)const{
        if(x<other.x) return true; else if(x>other.x) return false;
        if(h>other.h) return true; else if(h<other.h) return false;
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<node> mem(buildings.size()*2, node());
        map<int, int> mp; map<int,int>::iterator p;
        int i,h;
        for(i=0;i<buildings.size();++i){
            mem[i*2]=node(buildings[i][0],buildings[i][2],true);
            mem[i*2+1]=node(buildings[i][1],buildings[i][2],false);
        }
        sort(mem.begin(), mem.end());
        vector<vector<int>> ans;
        vector<int> ta;
        int heigh=-1; // 之前的高度
        for(i=0;i<mem.size();++i){
            h=mem[i].h;
            if(mem[i].isAdd){ // 增加高度
                if((p=mp.find(h))==mp.end()) mp.emplace(h, 1); 
                else mp[h]=p->second+1;
            }
            else { // 删除高度
                if((p=mp.find(h))->second==1) mp.erase(p); 
                else mp[h]=p->second-1;
            }
            // 错误点：保证同一个位置的所有数据都处理完再做判断
            if(i+1<mem.size()&&mem[i+1].x==mem[i].x) continue; 
            // 找到当前最大值
            if(mp.size()) h=(*(--mp.end())).first;
            else h=0;
            if(h!=heigh){
                ta=vector<int>(2); ta[0]=mem[i].x, ta[1]=h;
                ans.push_back(ta);
            }
            heigh=h;
        }
        return ans;
    }
};