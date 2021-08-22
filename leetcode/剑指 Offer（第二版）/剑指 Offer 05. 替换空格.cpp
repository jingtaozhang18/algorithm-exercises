// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int i,count=0,j,len=s.size();
        for(i=0;i<len;++i)if(s[i]==' ')count++;
        s.resize(len+count*2, ' ');
        for(j=len-1,i=s.size()-1; j>=0; --j){
            if(s[j]==' ')s[i--]='0',s[i--]='2',s[i--]='%';
            else s[i--]=s[j];
        }
        return s;
    }
};

// 复习
class Solution {
public:
    string replaceSpace(string s) {
        int i, n=s.size(), k=0;
        for(i=0;i<n;++i) if(s[i]==' ') ++k;
        if(k){
            s.resize(n+2*k);
            for(i=n-1, k=2*k+n-1;k>i;--i){
                if(s[i]==' ') s[k--]='0', s[k--]='2', s[k--]='%';
                else s[k--]=s[i];
            }
        }
        return s;
    }
};