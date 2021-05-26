// https://leetcode-cn.com/problems/group-anagrams/
#include<bits/stdc++.h>
using namespace std;

struct unionStruct{
    vector<int> arr;
    unionStruct(int n){
        arr=vector<int>(n);
        for(int i=0;i<n;++i) arr[i]=i;
    }
    int find(int i){
        if(arr[i]==i) return i;
        return arr[i]=find(arr[arr[i]]);
    }
    void junion(int i, int j){
        i=find(i);
        j=find(j);
        if(i!=j) arr[i]=j;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size(), i, j, k;
        unionStruct us(n);
        vector<string> origin(strs);
        for(i=0;i<n;++i) sort(strs[i].begin(), strs[i].end());
        for(i=0;i<n;++i){
            for(j=i+1;j<n;++j){
                if(strs[i]==strs[j]) us.junion(i, j);
            }
        }
        unordered_map<int, vector<string>> amp;
        for(i=0;i<n;++i) amp[us.find(i)].push_back(origin[i]);
        vector<vector<string>> ans;
        for(auto p=amp.begin(); p!=amp.end();++p){
            ans.push_back(p->second);
        }
        return ans;
    }
};

// 没必要用并查集
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};