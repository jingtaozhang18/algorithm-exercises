// https://leetcode-cn.com/contest/weekly-contest-237/problems/check-if-the-sentence-is-pangram/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> st;
        for(auto&e:sentence){
            st.insert(e);
        }
        return st.size()==26;
    }
};