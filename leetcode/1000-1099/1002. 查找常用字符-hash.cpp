// https://leetcode-cn.com/problems/find-common-characters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int ans[26], sig[26], i, j;
        memset(ans, 0, sizeof ans);
        memset(sig, 0, sizeof sig);
        for(i=0;i<A[0].size();++i) ans[A[0][i]-'a']++;
        for(i=1;i<A.size();++i){
            memset(sig, 0, sizeof sig);
            for(j=0;j<A[i].size();++j) sig[A[i][j]-'a']++;
            for(j=0;j<26;j++) ans[j]=min(ans[j], sig[j]);
        }
        vector<string> res;
        for(i=0;i<26;++i) while(ans[i]--) res.push_back(string(1, 'a'+i));
        return res;
    }
};