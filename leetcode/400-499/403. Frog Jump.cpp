// https://leetcode-cn.com/problems/frog-jump/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> st; // 记录不能跳的选项
    int jfind(vector<int>& stones, int left, int tar){
        int right=stones.size()-1, mid;
        while(left<=right){
            mid=(left+right)/2;
            if(stones[mid]==tar) return mid;
            else if(stones[mid]<tar) left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
    bool jgo(vector<int>& stones, int index, int k){ // 现在在第i块石头上，上一次跳跃了k个位置
        string key=to_string(index)+","+to_string(k);
        if(index==stones.size()-1) return true;
        if(st.find(key)!=st.end()) return st[key];
        int i, x, y; 
        for(i=-1;i<2;++i){
            x=stones[index]+k+i;
            if(x<=index) continue;
            y=jfind(stones, index+1, x);
            if(y==-1) continue;
            if(jgo(stones, y, k+i)) return st[key]=true;
        }
        return st[key]=false;
    }

    bool canCross(vector<int>& stones) {
        return stones[1]==1&&jgo(stones, 1, 1);
    }
};