// https://leetcode-cn.com/problems/h-index/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int x, i, j, m=citations.size();
        for(i=0;i<m;++i){
            x=m-i; // >=citations[i]的数量是x篇
            if(x<=citations[i]) return x;
        }
        return 0;
    }
};
