// https://leetcode-cn.com/problems/time-based-key-value-store/
#include<bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> mp;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        auto p=mp.find(key);
        if(p==mp.end()) return "";
        auto q=p->second.upper_bound(timestamp);
        if(q==p->second.begin()) return "";
        --q;
        return q->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */