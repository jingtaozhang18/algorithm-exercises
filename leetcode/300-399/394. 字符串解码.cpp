// https://leetcode-cn.com/problems/decode-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int readInt(string&s, int& i){
        int ans=0;
        for(;s[i]!='[';++i) ans*=10, ans+=s[i]-'0';
        i++; // 越过]
        return ans;
    }
    string jgo(string&s, int& i){
        string ans="";
        for(;i<s.size()&&s[i]!=']';++i){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) ans+=s[i]; // 字符
            else{
                int times=readInt(s, i);
                string add=jgo(s, i);
                while(times--) ans.append(add);
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int i=0;
        return jgo(s, i);
    }
};