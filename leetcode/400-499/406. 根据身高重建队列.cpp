// https://leetcode-cn.com/problems/queue-reconstruction-by-height/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int high, need;
    node(){}
    node(int high, int need):high(high),need(need){}
    bool operator<(const node& other) const{
        if(need<other.need) return true; else if(need>other.need) return false;
        if(high<other.high) return true;
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<node> arr(people.size());
        vector<node> ans;
        int i,j,k,t;
        for(i=0;i<people.size();++i) arr[i].high=people[i][0], arr[i].need=people[i][1];
        sort(arr.begin(), arr.end());
        for(i=0;i<people.size();++i){
            ans.push_back(arr[i]);
            for(j=0,t=0;j<ans.size()-1&&t<arr[i].need;++j) {if(ans[j].high>=arr[i].high) ++t;} // 找到了n个满足的
            for(;j<ans.size()-1;++j) if(ans[j].high>=arr[i].high) break;
            if(j==ans.size()-1) continue; // 数量刚刚好
            for(k=ans.size()-2;k>=j;--k) ans[k+1]=ans[k]; // 后移位置，流出k空位
            ans[++k]=arr[i]; // 插队
        }
        vector<vector<int>> ta(people.size(), vector<int>(2,0));
        for(i=0;i<people.size();++i) ta[i][0]=ans[i].high,ta[i][1]=ans[i].need;
        return ta;
    }
};