// https://leetcode-cn.com/problems/binary-watch/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jcalc(int val){
        int ans=0;
        while(val){
            ans++;
            val=val&(val-1);
        }
        return ans;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        unordered_map<int, vector<int>> hour;
        unordered_map<int, vector<int>> minu;
        vector<string> ans;
        int i, j;
        for(i=0;i<12;++i) hour[jcalc(i)].push_back(i);
        for(i=0;i<60;++i) minu[jcalc(i)].push_back(i);
        for(i=0;i<=turnedOn;++i){
            j=turnedOn-i;
            for(auto &x:hour[i]){
                for(auto &y:minu[j]){
                    string t=to_string(x)+":"+(y<=9?"0":"")+to_string(y);
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};