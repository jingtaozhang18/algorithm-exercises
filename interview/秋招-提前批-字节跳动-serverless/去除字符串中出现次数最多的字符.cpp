// 去掉字符串中出现次数最多的字符，如果有多个字符出现的次数相同，去掉第一次出现的
#include<bits/stdc++.h>
using namespace std;

string calc(string &str){
    unordered_map<char, int> mp;
    int i, j, m=str.size(), val=-1;
    char cr;
    for(i=m-1;i>=0;--i){
        mp[str[i]]++;
        if(mp[str[i]]>=val){
            val=mp[str[i]], cr=str[i];
        }
    }
    string ans(m-val, ' ');
    for(i=0,j=0;i<m;++i){
        if(str[i]!=cr) ans[j++]=str[i];
    }
    return ans;
}

int main(void){
    string str="asdfas";
    cout<<calc(str)<<"#"<<endl;
    return 0;
}