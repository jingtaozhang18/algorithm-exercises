// https://leetcode-cn.com/problems/sort-characters-by-frequency/
#include<bits/stdc++.h>
using namespace std;

struct node{
    char c;
    int times;
    node(char c, int times):c(c),times(times){}
    bool operator<(const node& other) const{ // 比较函数怎么写，别忘记了呀
        return this->times>other.times;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, int> mp;
        for(auto&c:s) mp[c]++;
        vector<node> arr;
        for(auto&p:mp) arr.push_back(node(p.first, p.second));
        sort(arr.begin(), arr.end());
        int i, t;
        for(auto &p:arr){
            t=p.times;
            while(t--) s[i++]=p.c;
        }
        return s;
    }
};
