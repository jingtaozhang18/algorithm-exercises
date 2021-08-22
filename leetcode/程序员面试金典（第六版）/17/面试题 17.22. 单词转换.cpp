// https://leetcode-cn.com/problems/word-transformer-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judge(string&a, string&b){
        int i=0, diff=0;
        for(i=0;i<a.size();++i) if(a[i]!=b[i]) diff++;
        return diff==1;
    }
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> mp;
        int i, j;
        string a, b;
        // 构建图
        for(i=0;i<=wordList.size();++i){
            if(i==wordList.size()) a=beginWord;
            else a=wordList[i];
            for(j=i==wordList.size()?0:i+1;j<wordList.size();++j){
                b=wordList[j];
                if(judge(a, b)){
                    mp[a].push_back(b);
                    mp[b].push_back(a);
                }
            }
        }
        set<string> st;
        if(mp.find(endWord)==mp.end()) return vector<string>();
        // bfs遍历搜索
        queue<string> que;
        que.push(beginWord);
        st.insert(beginWord);
        unordered_map<string, string> path;
        while(!que.empty()){
            a=que.front();
            que.pop();
            for(auto b: mp[a]){
                if(st.find(b)==st.end()){
                    path[b]=a;
                    st.insert(b);
                    que.push(b);
                    if(b==endWord) break;
                }
            }
        }
        if(path.find(endWord)==path.end()) return vector<string>();
        stack<string> sta;
        a=endWord;
        while(path.find(a)!=path.end()){
            sta.push(a);
            a=path[a];
        }
        vector<string> ans;
        ans.push_back(beginWord);
        while(sta.empty()==false){
            ans.push_back(sta.top());
            sta.pop();
        }
        return ans;
    }
};