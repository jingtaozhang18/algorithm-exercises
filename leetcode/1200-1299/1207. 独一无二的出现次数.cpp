// https://leetcode-cn.com/problems/unique-number-of-occurrences/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int i;
        map<int, int> mp;
        map<int, int>::iterator p;
        for(i=0;i<arr.size();i++) if((p=mp.find(arr[i]))==mp.end()) mp[arr[i]]=1; else p->second++;
        set<int> st;
        for(p=mp.begin();p!=mp.end();++p) {
            if(st.find(p->second)!=st.end()) return false;
            st.insert(p->second);
        }
        return true;
    }
};