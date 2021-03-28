// https://leetcode-cn.com/submissions/detail/160765507/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        int i, j, n=word.size();
        bool flag=false;
        for(i=0;i<n;++i){
            if(word[i]>='a'&&word[i]<='z'){
                word[i]=' ';
            }
        }
        unordered_set<string> st; // 数字可能会超过范围
        for(i=0;i<n;){
            if(word[i]>='0'&&word[i]<='9'){
                for(j=i;j<n;++j) if(word[j]==' ') break;
                for(;i<j&&word[i]=='0';++i);  //  正确处理前缀零的问题
                st.insert(word.substr(i, j-i));
                // cout<<word.substr(i, j-i)<<endl;
                i=j+1;
            }else{
                ++i;
            }
        }
        return st.size();
    }
};