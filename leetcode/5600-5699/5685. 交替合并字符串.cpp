// https://leetcode-cn.com/problems/merge-strings-alternately/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.size(), n=word2.size(), i=0, j=0, k=0;
        bool flag=true;
        string ans(m+n, ' ');
        while(i<m&&j<n){
            if(flag) ans[k++]=word1[i++];
            else ans[k++]=word2[j++];
            flag=!flag;
        }
        while(i<m) ans[k++]=word1[i++];
        while(j<n) ans[k++]=word2[j++];
        return ans;
    }
};