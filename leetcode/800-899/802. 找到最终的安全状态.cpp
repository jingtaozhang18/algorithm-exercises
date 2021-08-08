// https://leetcode-cn.com/problems/find-eventual-safe-states/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>* color;
    vector<vector<int>>* graph;
    bool jdfs(int cur){ // 返回是否安全
        (*color)[cur]=1; // 被发现了
        bool ans=true;
        for(int next:(*graph)[cur]){
            if((*color)[next]==0){
                if(jdfs(next)==false) ans=false; 
            }else if((*color)[next]==1||(*color)[next]==3){ // 1是当前正在遍历的，3是之前遍历的不安全点
                ans=false;
            }
        }
        if(ans==false) (*color)[cur]=3; // 不安全的节点
        else (*color)[cur]=2;
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m=graph.size(), i;
        this->graph = &graph;
        color = new vector<int>(m);
        for(i=0;i<m;++i){
            if((*color)[i]==0) 
                jdfs(i);
        }
        vector<int> ans;
        for(i=0;i<m;++i){
            if((*color)[i]==2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
