// https://leetcode-cn.com/problems/split-array-largest-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jgo(vector<int>& split, vector<long long>& acc, map<int, set<int>>& mp, int i, int m){
        if(split[i+1]-split[i]==1) return false; // 长度为1无法优化
        long long t=acc[split[i+1]]-acc[split[i]],x;
        if(i>0){ // 和左边的区间优化
            if(acc[split[i]+1]-acc[split[i-1]]<t){
                x=acc[split[i]]-acc[split[i-1]];
                mp[x].erase(mp[x].find(i-1));
                mp[t].erase(mp[t].find(i));
                if(mp[x].size()==0) mp.erase(mp.find(x));
                if(mp[t].size()==0) mp.erase(mp.find(t));
                split[i]++;
                x=acc[split[i]]-acc[split[i-1]];
                t=acc[split[i+1]]-acc[split[i]];
                mp[x].insert(i-1);
                mp[t].insert(i);
                return true;
            }
        }
        if(i<m-1){
            if(acc[split[i+2]]-acc[split[i+1]-1]<t){
                x=acc[split[i+2]]-acc[split[i+1]];
                mp[x].erase(mp[x].find(i+1));
                mp[t].erase(mp[t].find(i));
                if(mp[x].size()==0) mp.erase(mp.find(x));
                if(mp[t].size()==0) mp.erase(mp.find(t));
                split[i+1]--;
                x=acc[split[i+2]]-acc[split[i+1]];
                t=acc[split[i+1]]-acc[split[i]];
                mp[x].insert(i+1);
                mp[t].insert(i);
                return true;
            }
        }
        return false;
    }
    int splitArray(vector<int>& nums, int m) {
        long long t;
        int i,j,size=nums.size();
        vector<int> split(m+1,0); // [split[i],split[i+1]) 是一个区间
        map<int, set<int>> mp; // 区间和对应的最大值
        map<int, set<int>>::iterator p; // 区间和对应的最大值
        map<int, set<int>>::reverse_iterator rp; // 区间和对应的最大值
        set<int>::iterator sp;
        bool opti=true,topti; // 是否有优化
        vector<long long> acc(size+1,0);
        for(i=0;i<size;++i) acc[i+1]=acc[i]+nums[i]; // 累加和
        for(i=0;i<m;++i) split[i]=i;
        split[i]=size; // 设置标杆
        for(i=1;i<=m;++i) mp[acc[split[i]]-acc[split[i-1]]].insert(i-1);
        while(opti){
            opti=false;
            for(rp=mp.rbegin();rp!=mp.rend();++rp){
                topti=false;
                for(sp=rp->second.begin();!topti&&sp!=rp->second.end();++sp){
                    topti=jgo(split, acc, mp, (*sp), m);
                }
                if(topti) opti=true;
            }
        }
        p=mp.end(); p--;
        for(i=0;i<=m;++i)cout<<split[i]<<" "; cout<<endl;
        return p->first;
    }
};