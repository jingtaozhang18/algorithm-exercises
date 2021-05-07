// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mp[10]{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void jgo(string&s, int index, vector<string>&ans, string& path){
        if(index==s.size()){
            ans.push_back(path);
            return;
        }
        int j;
        path=path+" ";
        for(j=0;j<mp[s[index]-'0'].size();++j){
            path[path.size()-1]=mp[s[index]-'0'][j];
            jgo(s, index+1, ans, path);
        }
        path=path.substr(0, path.size()-1);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        string path;
        jgo(digits, 0, ans, path);
        return ans;
    }
};