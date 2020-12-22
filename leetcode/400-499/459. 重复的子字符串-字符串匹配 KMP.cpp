// https://leetcode-cn.com/problems/repeated-substring-pattern/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};

class Solution {
public:
    int jgo(string haystack, string needle){
        int i,j;
        vector<int> arr(needle.size(),0);
        if(needle.size()>0) arr[0]=-1; else return 0;
        if(needle.size()>1) arr[1]=0;
        for(i=2;i<needle.size();++i){
            for(j=arr[i-1];j!=-1&&needle[i-1]!=needle[j];j=arr[j]);
            arr[i]=j+1;
        }
        for(i=0,j=0;i<haystack.size()&&j<needle.size();){
            if(haystack[i]==needle[j]){
                ++i, ++j;
            }else if(arr[j]==-1){
                i++;
            }else{
                j=arr[j];
            }
        }
        return j==needle.size()?i-j:-1;
    }
    bool repeatedSubstringPattern(string s) {
        return jgo((s+s).substr(1, s.size()*2-1), s) != s.size()-1;
    }
};