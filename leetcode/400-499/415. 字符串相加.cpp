// https://leetcode-cn.com/problems/add-strings/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1,j=num2.size()-1;
        char c;
        bool carry=false; // 进位
        string ans="";
        while(i>=0||j>=0||carry){
            c=(i>=0?num1[i--]:'0')+(j>=0?num2[j--]:'0')-'0'+(carry?1:0);
            if(c>'9') carry=true, c-=10;
            else carry=false;
            ans=c+ans;
        }
        return ans;
    }
};