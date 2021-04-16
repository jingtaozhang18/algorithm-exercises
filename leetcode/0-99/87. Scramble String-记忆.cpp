// https://leetcode-cn.com/problems/scramble-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // arr 是不需要4维的，减少不必要的存储，加快运行速度
    short arr[40][40][40];
    bool jgo(string&s1, string&s2, int ai, int aj, int bi, int bj){
        if(arr[ai][aj][bi]==-1) return false;
        if(arr[ai][aj][bi]==1) return true;
        short mem[26], i, diff=0, n=aj-ai+1;
        if(n==1) {
            if(s1[ai]==s2[bi]) return true;
            else return false;
        }
        for(i=0;i<26;++i) mem[i]=0;
        for(i=0;i<n-1;++i){
            if(mem[s1[ai+i]-'a']<0) diff--;
            else diff++;
            mem[s1[ai+i]-'a']++;
            if(mem[s2[bi+i]-'a']<=0) diff++;
            else diff--;
            mem[s2[bi+i]-'a']--;
            if(diff==0){ // 递归检查
                if(jgo(s1, s2, ai, ai+i, bi, bi+i)){
                    // arr[ai][ai+i][bi][bi+i]=1;
                    if(jgo(s1, s2, ai+i+1, aj, bi+i+1, bj)){
                        // arr[ai+i+1][aj][bi+i+1][bj]=1;
                        arr[ai][aj][bi]=1;
                        return true;
                    }
                }
            }
        }
        for(i=0;i<26;++i) mem[i]=0;
        diff=0;
        for(i=0;i<n-1;++i){
            if(mem[s1[ai+i]-'a']<0) diff--;
            else diff++;
            mem[s1[ai+i]-'a']++;
            if(mem[s2[bj-i]-'a']<=0) diff++;
            else diff--;
            mem[s2[bj-i]-'a']--;
            if(diff==0){ // 递归检查
                if(jgo(s1, s2, ai, ai+i, bj-i, bj)){
                    // arr[ai][ai+i][bj-i][bj]=1;
                    if(jgo(s1, s2, ai+i+1, aj, bi, bj-i-1)){
                        // arr[ai+i+1][aj][bi][bj-i-1]=1;
                        arr[ai][aj][bi]=1;
                        return true;
                    }
                }
            }
        }
        arr[ai][aj][bi]=-1;
        return false;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        for(int i=0;i<40;++i) for(int j=0;j<40;++j)
            for(int k=0;k<40;++k) arr[i][j][k]=0;
        return jgo(s1, s2, 0, s1.size()-1, 0, s2.size()-1);
    }
};