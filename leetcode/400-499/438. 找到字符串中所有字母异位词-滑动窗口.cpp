// https://leetcode-cn.com/problems/permutation-in-string/
#include<bits/stdc++.h>
using namespace std;
// 567. 字符串的排列-滑动窗口 进阶版
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left=0, right=0; // [left, right)
        char c; bool nomarl;
        unordered_map<char, int> need, have;
        for(char c: p) need[c]++;
        vector<int> ans;
        while(right<s.size()){
            nomarl=true;
            while(right<s.size()&&right-left<p.size()){
                c=s[right]; have[c]++, right++;
                if(have[c]>need[c]) {
                    nomarl=false;
                    break; // 多了
                }
            }
            if(nomarl&&right-left==p.size()) { // 错误点：长度相等了，不一定代表匹配到了
                ans.push_back(left);
                c=s[left]; have[c]--, left++;
            }else {
                while(left<right){
                    c=s[left]; have[c]--, left++;
                    if(have[c]==need[c]) break; // 去掉了多的元素
                }
            }
        }
        return ans;
    }
};