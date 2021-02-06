// https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> map;
    int jgo(vector<int>& cardPoints, int i, int j, int k){
        if(k==0) return 0;
        string key=to_string(i)+","+to_string(j)+","+to_string(k);
        if(map.find(key)!=map.end()) return map[key];
        return map[key]=max(cardPoints[i]+jgo(cardPoints, i+1, j, k-1), cardPoints[j]+jgo(cardPoints, i, j-1, k-1));
    }
    int maxScore(vector<int>& cardPoints, int k) {
        map.clear();
        return jgo(cardPoints, 0, cardPoints.size()-1, k);
    }
};