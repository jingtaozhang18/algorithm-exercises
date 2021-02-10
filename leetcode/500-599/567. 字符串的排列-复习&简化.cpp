// https://leetcode-cn.com/problems/permutation-in-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left=0, right=0, hit=0, miss=0; // [left, right)
        char c;
        unordered_map<char, int> map;
        for(char c: s1) map[c]++;
        while(right<s2.size()){
            c=s2[right++];
            map[c]--;
            if(map[c]>=0) hit++;
            else miss++;
            while(left<=right&&map[s2[left]]<0){
                map[s2[left++]]++;
                miss--;
            }
            if(hit==s1.size()&&miss==0) return true;
        }
        return false;
    }
};