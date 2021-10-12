// https://leetcode-cn.com/problems/number-of-atoms/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jread(string &str, int &i){
        int ans=0;
        while(i<str.size()&&str[i]>='0'&&str[i]<='9') ans*=10, ans+=str[i]-'0', i++;
        --i;
        if(ans==0) return 1;
        return ans;
    }
    string countOfAtoms(string formula) {
        stack<map<string, int>> sta;
        sta.push(map<string, int>());
        int i, k, m=formula.size();
        string c;
        for(i=0;i<m;++i){
            if(formula[i]=='('){
                sta.push(map<string, int>());
            }else if(formula[i]==')'){
                auto mp=sta.top(); sta.pop();
                ++i, k=jread(formula, i);
                for(auto p:mp) sta.top()[p.first]+=p.second*k;
            }else{
                c=formula[i];
                while(i+1<m&&formula[i+1]>='a'&&formula[i+1]<='z') c+=formula[i+1], ++i;
                ++i;
                k=jread(formula, i);
                sta.top()[c]+=k;
            }
        }
        while(sta.size()>1){
            auto mp=sta.top(); sta.pop();
            for(auto p:mp) sta.top()[p.first]+=p.second;
        }
        string ans;
        for(auto p:sta.top()) ans+=(p.first+(p.second>1?to_string(p.second):""));
        return ans;
    }
};
