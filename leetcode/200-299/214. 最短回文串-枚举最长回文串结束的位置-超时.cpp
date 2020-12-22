// https://leetcode-cn.com/problems/shortest-palindrome/
#include<bits/stdc++.h>
using namespace std;

// 通用找最长回文子串的方式，超时
class Solution {
public:
    int jgo(string& s, int l, int r){
        while(l>=0&&r<s.size()&&s[l]==s[r])--l,++r;
        return r-l-1;
    }
    string shortestPalindrome(string s) {
        int sl=0,i,j,a,b,as,bs;
        for(i=s.size()-1;i>=0;--i) { // 找到以s[0]为开始的最长回文串
            as=jgo(s,i,i);
            a=i-as/2;
            bs=jgo(s,i,i+1);
            b=i+1-bs/2;
            if(a==0&&as>sl) sl=as;
            if(b==0&&bs>sl) sl=bs;
        }
        j=s.size()-sl; // 需要添加的串
        string ans=s.substr(sl, j)+s;
        for(i=0,--j;i<j;++i,--j) a=ans[i],ans[i]=ans[j],ans[j]=a;
        return ans;
    }
};

// 拍脑袋找从0开始的最长回文子串，超时
class Solution {
public:
    bool jgo(string& s, int l, int r){ // 找到以i,j向两边扩散的最大回文范围
        while(l<r&&s[l]==s[r]) ++l,--r;
        return l>=r;
    }
    string shortestPalindrome(string s) {
        int sl=0,i,j,a,b,as,bs;
        for(i=s.size()-1;i>=0;--i) { // 找到以s[0]为开始的最长回文串
            if(jgo(s,0,i)) {
                sl=i+1;
                break;
            }
        }
        j=s.size()-sl; // 需要添加的串
        string ans=s.substr(sl, j)+s;
        for(i=0,--j;i<j;++i,--j) a=ans[i],ans[i]=ans[j],ans[j]=a;
        return ans;
    }
};