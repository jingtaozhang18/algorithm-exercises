// https://leetcode-cn.com/problems/reverse-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j=s.size()-1;
        while(i<j){
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];
            // swap(s[i], s[j]);
            ++i, --j;
        }
    }
};
