// https://leetcode-cn.com/problems/top-k-frequent-words/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int times;
    string word;
    node(){}
    node(string w, int t):word(w),times(t){};
    bool operator<(const node& other) const {
        if(this->times==other.times) return this->word<other.word;
        return this->times>other.times;
    }
};

// 时间复杂度：O(nlogn)， 空间复杂度O(n)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        vector<string> ans(k);
        for(auto &e: words) mp[e]++;
        int i, n=mp.size();
        vector<node> arr(n);
        auto p=mp.begin();
        for(i=0;i<n;++i,++p) arr[i]=node(p->first, p->second);
        sort(arr.begin(), arr.end());
        for(i=0;i<k;++i) ans[i]=arr[i].word;
        return ans;
    }
};

// 时间复杂度：O(nlogk)， 空间复杂度O(n)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        vector<string> ans(k);
        for(auto &e: words) mp[e]++;
        int i, n=mp.size();
        priority_queue<node, vector<node>> que;
        auto p=mp.begin();
        for(;p!=mp.end();++p){
            que.push(node(p->first, p->second));
            if(que.size()>k) que.pop();
        }
        for(i=k-1;i>=0;--i) {
            ans[i]=que.top().word;
            que.pop();
        }
        return ans;
    }
};