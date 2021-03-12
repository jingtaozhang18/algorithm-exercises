// https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool readInt(string &s, int &i, int &ans){ // 是数读数，返回true；不识数返回false
        ans=0;
        if(s[i]=='#'){
            i+=2;
            return false;
        } else{
            while(i<s.size()&&s[i]!=',') ans*=10, ans+=s[i]-'0', ++i; // 危险操作，容易溢出
            ++i;
            return true;
        }
    }
    bool isValidSerialization(string preorder) {
        int i=0, n=preorder.size(), x;
        bool over=false;
        stack<int> sta;
        while(i<n){
            if(over) return false;
            if(readInt(preorder, i, x)){
                sta.push(x);
            }else{
                if(sta.size()) sta.pop();
                else over=true;
            }
        }
        return over;
    }
};

// 简化版，没有必要用栈来计数，太奢侈。 从槽位的角度讲，比较容易理解
// 每次读到一个数字，会消耗掉一个槽位，同时产生两个新位置
// 每次读到一个终结符，会消耗掉一个槽位
// 槽位初始化为1个，合法的最终结果是0
// 槽位数量不能小于0，并且，一旦为0，就意味这终止
class Solution {
public:
    bool readInt(string &s, int &i){
        if(s[i]=='#'){
            i+=2;
            return false;
        } else{
            while(i<s.size()&&s[i]!=',') ++i;
            ++i;
            return true;
        }
    }
    bool isValidSerialization(string preorder) {
        int i=0, n=preorder.size(), x;
        int pos = 1;
        bool over=false;
        while(i<n){
            if(over) return false;
            if(readInt(preorder, i)){
                pos+=1;
            }else{
                pos-=1;
                if(pos==0) over=true;
                if(pos<0) return false;
            }
        }
        return pos==0;
    }
};