// https://leetcode-cn.com/problems/implement-strstr/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
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
};