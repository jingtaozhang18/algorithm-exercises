// https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
#include<bits/stdc++.h>
using namespace std;

struct node{
    node *next[26];
    string con;
    node(){
        con="";
        for(int i=0;i<26;++i) next[i]=nullptr;
    }
};

class Solution {
public:
    node* root;
    void build(string&s){
        node* t=root;
        for(auto &c:s){
            if(!t->next[c-'a']) t->next[c-'a']=new node();
            t=t->next[c-'a'];
        }
        t->con=s;
    }
    void jgo(string&s, int index, unordered_map<string, int>&st, int left, vector<int>&ans){
        // 开始检索
        node *t=root;
        for(int i=index;i<s.size();++i){
            if(t->next[s[i]-'a']) t=t->next[s[i]-'a'];
            else return;
            if(t->con.size()){
                if(st[t->con]>0){
                    st[t->con]--;
                    left--;
                    if(left==0) ans.push_back(index);
                    t=root; // 重新开始检索
                }else return;
            }
        }
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        root=new node();
        unordered_map<string, int> st;
        vector<int> ans;
        int left=0;
        for(auto &e:words) {st[e]++; build(e); left++;}
        for(int i=0;i<s.size()-words.size()*words[0].size()+1;++i){
            unordered_map<string, int> tst = st;
            jgo(s, i, tst, left, ans);
        }
        return ans;
    }
};
