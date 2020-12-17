// https://leetcode-cn.com/problems/basic-calculator/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int readNum(string&s, int& index){
        int ans=0;
        for(;index<s.size()&&s[index]>='0'&&s[index]<='9';++index) ans=ans*10+(s[index]-'0');
        return ans;
    }
    int jgo(string&s, int& index){
        int ans=0; bool flag=true; // 加减标志位
        for(;index<s.size();){ // 每个操作结束之后，保证下标停在下一个需要处理的字符上
            if(s[index]==' ') {++index; continue;}
            else if(s[index]=='('){
                ++index;
                if(flag) ans+=jgo(s, index);
                else ans-=jgo(s, index);
            }else if(s[index]==')'){
                ++index;
                return ans;
            }else if(s[index]=='+') flag=true, index+=1;
            else if(s[index]=='-') flag=false, index+=1;
            else {
                if(flag) ans+=readNum(s, index);
                else ans-=readNum(s, index);
            }
        }
        return ans;
    }
    int calculate(string s) {
        int index=0;
        return jgo(s, index);
    }
};