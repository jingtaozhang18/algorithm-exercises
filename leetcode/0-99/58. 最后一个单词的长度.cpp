// https://leetcode-cn.com/problems/length-of-last-word/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, n=s.size(), acc=0;
        i=n-1;
        while(i>=0&&s[i]==' ') --i;
        while(i>=0&&s[i]!=' ') acc++, --i;
        return acc;
    }
};