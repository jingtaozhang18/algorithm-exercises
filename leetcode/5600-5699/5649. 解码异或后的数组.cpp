// https://leetcode-cn.com/problems/decode-xored-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        int i;
        for(i=0;i<encoded.size();++i){
            first=encoded[i]^first;
            ans.push_back(first);
        }
        return ans;
    }
};