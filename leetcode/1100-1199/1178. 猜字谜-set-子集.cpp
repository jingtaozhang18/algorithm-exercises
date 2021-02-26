// https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int val, i, j, size=puzzles.size(), flag=0;
        unordered_map<int, int> mp;
        for(auto e:words) {
            for(i=0,val=0;i<e.size();++i) val=val|(1<<(e[i]-'a'));
            mp[val]++;
        }
        vector<int> ans(size);
        for(i=0;i<size;++i){
            for(flag=0;flag<1<<7;++flag){
                if(!(flag&1)) continue;
                for(j=0,val=0;j<puzzles[i].size();++j){
                    if((1<<j)&flag) val=val|(1<<(puzzles[i][j]-'a'));
                }
                auto p=mp.find(val);
                if(p!=mp.end()) ans[i]+=p->second;
            }
        }
        return ans;
    }
};