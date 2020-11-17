// https://leetcode-cn.com/problems/rearrange-string-k-distance-apart/
#include<bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(const pair<char,int>&a, const pair<char,int>&b)const{
        return a.second<b.second;
    }
};
class Solution {
public:
    string rearrangeString(string s, int k) {
        map<char,int> fre; // 统计单词出现的频率
        map<char,int>::iterator p;
        priority_queue<pair<char, int>,vector<pair<char, int>>,cmp> pq; // 优先级队列
        pair<char, int> pqp;
        queue<char> que; // 等待重新加入优先级队列的字符
        int i; char tc;
        string ans="";
        for(auto c:s){ // 统计频率
            if((p=fre.find(c))!=fre.end()) i=p->second+1;
            else i=1;
            fre[c]=i;
        }
        // 构建优先级队列
        for(p=fre.begin();p!=fre.end();++p) pq.emplace(p->first, p->second);
        // 出现次数高的优先出现
        while(!pq.empty()){
            pqp=pq.top(); pq.pop();
            ans+=pqp.first;
            que.push(pqp.first);
            fre[pqp.first]--;
            if(que.size()>=k){
                tc=que.front();
                if(fre[tc]) pq.emplace(tc, fre[tc]);
                que.pop();
            }
        }
        return ans.size()==s.size()?ans:"";
    }
};