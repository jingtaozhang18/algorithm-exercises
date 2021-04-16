// https://leetcode-cn.com/problems/scramble-string/
#include<bits/stdc++.h>
using namespace std;

// 效率貌似更低
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int i, j, k, l, diff, n=s1.size();
        if(n!=s2.size()) return false;
        bool arr[n][n][n+1]; // arr[i][j][k] 长度为k的时候，s1在i的位置开始，s2在j的位置开始
        short mem[26];
        for(i=0;i<n;++i) for(j=0;j<n;++j)for(int k=0;k<n+1;++k) arr[i][j][k]=(k==0)|(k==1&&s1[i]==s2[j]);
        for(k=2;k<=n;++k){
            for(i=0;i<=n-k;++i){
                for(j=0;j<=n-k;++j){
                    for(l=0;l<26;++l) mem[l]=0;
                    for(l=0, diff=0;l<k;++l){
                        if(mem[s1[i+l]-'a']>=0) diff++; else diff--;
                        mem[s1[i+l]-'a']++;
                        if(mem[s2[j+l]-'a']<=0) diff++; else diff--;
                        mem[s2[j+l]-'a']--;
                    }
                    if(diff==0){
                        for(l=1;l<k&&arr[i][j][k]==false;++l){
                            arr[i][j][k]=(arr[i][j][l]&arr[i+l][j+l][k-l])|(arr[i][j+k-l][l]&arr[i+l][j][k-l]);
                        }
                    }
                }
            }
        }
        return arr[0][0][n];
    }
};