// https://leetcode-cn.com/problems/compare-version-numbers/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(string&s,int &i){
        int ans=0;
        for(;i<s.size()&&s[i]!='.';++i) ans*=10, ans+=s[i]-'0';
        i++; // 错误点 移出.
        return ans;
    }
    int compareVersion(string version1, string version2) {
        int i=0,j=0,diff;
        while(i<version1.size()||j<version2.size()){
            diff=jgo(version1,i)-jgo(version2, j);
            if(diff>0) return 1;
            else if(diff<0) return -1;
            else continue;
        }
        return 0;
    }
};