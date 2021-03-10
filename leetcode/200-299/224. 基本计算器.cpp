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

// 复习，第二遍做做麻烦了，在jgo函数中可以设置基数为0，初始化是加法，就可以按照循环的逻辑来处理
class Solution {
public:
    int readInt(string &s, int &i){
        int ans=0;
        while(i<s.size()&&s[i]>='0'&&s[i]<='9') ans*=10, ans+=s[i]-'0', ++i;
        return ans;
    }
    inline void ignore(string &s, int &i){
        while(i<s.size()&&s[i]==' ') ++i;
    }
    int jgo(string &s, int &i){ // 处理单元 进入和退出操作
        int a, b;
        ignore(s, i);
        if(s[i]=='('){ // 获取最开始的数字
            a=jgo(s, ++i);
        }else{
            a=readInt(s, i);
        }
        while(i<s.size()&&s[i]!=')'){
            ignore(s, i);
            char op = s[i++];
            ignore(s, i);
            if(s[i]=='('){
                ++i;
                b=jgo(s, i);
            }else{
                b=readInt(s, i);
            }
            // cout<< a << " " << op << " " << b <<endl;
            if(op=='+') a+=b;
            else a-=b;
            ignore(s, i);
        }
        if(i<s.size()&&s[i]==')') ++i;
        return a;
    }

    int calculate(string s) {
        int i = 0;
        return jgo(s, i);
    }
};