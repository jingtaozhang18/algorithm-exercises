// https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // n个项目 m个组
        vector<set<int>> ai(n); // after_item
        vector<set<int>> bi(n);
        unordered_map<int, vector<int>> g2i; // 记录组中包含的item
        vector<int> ni(m);
        vector<int> ans_g;
        vector<int> ans_i;
        vector<int> mengmeng;
        int i, g;
        for(i=0;i<n;++i) { if(group[i]==-1) group[i]=m++; }
        vector<set<int>> ag(m); // after_group
        vector<set<int>> bg(m); // before_group
        // 构建邻接信息
        for(i=0;i<n;++i){
            for(auto e:beforeItems[i]){ // 前序
                if(group[e]!=group[i]){
                    ag[group[e]].insert(group[i]); //依赖自己的不算
                    bg[group[i]].insert(group[e]);
                }
                ai[e].insert(i);
                bi[i].insert(e);
            }
        }
        // 对组进行排序
        queue<int> que;
        for(i=0;i<m;++i) if(bg[i].size()==0) que.push(i);
        while(!que.empty()){
            i=que.front(); que.pop();
            ans_g.push_back(i);
            for(auto e:ag[i]){ // 取消前序
                auto p=bg[e].find(i);
                if(p!=bg[e].end()) bg[e].erase(p);
                if(bg[e].size()==0) que.push(e);
            }
        }
        if(ans_g.size()!=m) return vector<int>();
        // 对项目进行排序
        for(i=0;i<n;++i) if(bi[i].size()==0) que.push(i);
        while(!que.empty()){
            i=que.front(); que.pop();
            ans_i.push_back(i);
            for(auto e:ai[i]){ // 取消前序
                auto p=bi[e].find(i);
                if(p!=bi[e].end()) bi[e].erase(p);
                if(bi[e].size()==0) que.push(e);
            }
        }
        if(ans_i.size()!=n) return vector<int>();
        for(auto e:ans_i){
            g2i[group[e]].push_back(e);
        }
        for(auto e:ans_g){
            for(auto i:g2i[e]){
                mengmeng.push_back(i);
            }
        }
        return mengmeng;
    }
};