// https://leetcode-cn.com/problems/rabbits-in-forest/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int i, n=answers.size(), ans=0, x, a, b;
        unordered_map<int, int> mp;
        for(i=0;i<n;++i) mp[answers[i]]++;
        for(auto p:mp){
            a = p.first+1;
            b = p.second;
            x = b / a;
            if(b%a) ++x;
            ans+=a*x;
        }
        return ans;
    }
};