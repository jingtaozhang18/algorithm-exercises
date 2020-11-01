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