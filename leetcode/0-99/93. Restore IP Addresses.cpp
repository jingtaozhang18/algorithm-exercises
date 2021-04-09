// https://leetcode-cn.com/problems/restore-ip-addresses/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void jgo(string&s, int i, vector<int>& path, vector<string> & ans){
        int n=s.size(), m=path.size(), j;
        if(i==n&&m==4){
            ans.push_back(to_string(path[0])+"."+to_string(path[1])+"."+to_string(path[2])+"."+to_string(path[3]));
            return;
        }
        if(i==n||m>=4) return;
        j=i;
        int acc=s[j]-'0';
        path.push_back(acc);
        jgo(s, j+1, path, ans);
        path.pop_back();
        if(acc)
            for(int j=i+1;j<n;++j){
                acc*=10, acc+=s[j]-'0';
                if(acc<=255){
                    path.push_back(acc);
                    jgo(s, j+1, path, ans);
                    path.pop_back();
                }else{
                    break;
                }
            }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> path;
        jgo(s, 0, path, ans);
        return ans;
    }
};