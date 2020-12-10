// https://leetcode-cn.com/problems/permutation-in-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left=0, right=0; // [left, right)
        char c; bool nomarl;
        unordered_map<char, int> need, have;
        for(char c: s1) need[c]++;
        while(right<s2.size()){
            nomarl=true;
            while(right<s2.size()&&right-left<s1.size()){
                c=s2[right]; have[c]++, right++;
                if(have[c]>need[c]) {
                    nomarl=false;
                    break; // 多了
                }
            }
            if(nomarl&&right-left==s1.size()) { // 错误点：长度相等了，不一定代表匹配到了
                return true;
            }else {
                while(left<right){
                    c=s2[left]; have[c]--, left++;
                    if(have[c]==need[c]) break; // 去掉了多的元素
                }
            }
        }
        return false;
    }
};