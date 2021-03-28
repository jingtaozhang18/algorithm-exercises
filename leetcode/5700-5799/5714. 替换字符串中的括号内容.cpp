// https://leetcode-cn.com/problems/evaluate-the-bracket-pairs-of-a-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string readKey(string &s, int &i){
        ++i;
        int j=i;
        while(s[j]!=')') ++j;
        string key=s.substr(i, j-i);
        i=j+1;
        return key;
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        int i, j, n=s.size();
        map<string, string> mp;
        for(auto &e:knowledge){
            mp[e[0]]=e[1];
        }
        for(i=0;i<n;){
            if(s[i]=='('){
                string key = readKey(s, i);
                if(mp.find(key)==mp.end()) ans+="?";
                else ans+=mp[key];
            }else{
                for(j=i;j<n&&s[j]!='(';++j);
                ans+=s.substr(i, j-i);
                i=j;
            }
        }
        return ans;
    }
};