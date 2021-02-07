// https://leetcode-cn.com/problems/largest-merge-of-two-strings/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int m=word1.size(), n=word2.size(), i, j, x, y, k;
        bool flag;
        string ans(m+n, ' ');
        i=j=k=0;
        while(i<m||j<n){
            x=i, y=j;
            while(x<m||y<n){
                if(y==n||word1[x]>word2[y]) {flag=true; break;}
                else if(x==m||word1[x]<word2[y]) {flag=false; break;}
                else x++, y++;
            }
            if(flag) ans[k++]=word1[i++];
            else ans[k++]=word2[j++];
        }
        return ans;
    }
};