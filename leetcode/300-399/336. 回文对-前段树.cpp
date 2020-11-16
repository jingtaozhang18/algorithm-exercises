// https://leetcode-cn.com/problems/palindrome-pairs/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *child[26];
    node(){val=-1; memset(child, 0, sizeof(child));}
};

class Solution {
public:
    bool jgo(string&s, int l, int r){
        while(l<r){if(s[l]!=s[r]) return false;l++,r--;}
        return true;
    }
    void build(node*root, string& s, int index, bool order){
        for(int i=order?0:s.size()-1;order?i<s.size():i>=0;i+=order?1:-1){
            if(!root->child[s[i]-'a']) root->child[s[i]-'a']=new node();
            root=root->child[s[i]-'a'];
        }
        root->val=index;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        set<vector<int>> tans;
        vector<vector<int>> ans;
        vector<int> tmp(2,0);
        node *preRoot=new node(), *posRoot=new node(), *t;
        int i,j,a,b,c;
        for(i=0;i<words.size();++i)
            build(preRoot, words[i], i, true), build(posRoot, words[i], i, false);
        for(i=0;i<words.size();++i){ // 处理
            // 让当前单词在后面
            t=preRoot;
            if(t->val!=-1&&t->val!=i&&jgo(words[i],0,words[i].size()-1)){ // 特例
                tmp[1]=i, tmp[0]=t->val;
                tans.insert(tmp);
                tmp[0]=i, tmp[1]=t->val;
                tans.insert(tmp);
            }
            for(j=words[i].size()-1;j>=0;--j){
                if(t->child[words[i][j]-'a']){
                    t=t->child[words[i][j]-'a'];
                    if(t->val!=-1&&t->val!=i&&jgo(words[i], 0, j-1)){ // 是回文
                        tmp[0]=t->val, tmp[1]=i;
                        tans.insert(tmp);
                    }
                }else break;
            }
            // 让当前单词在前面
            t=posRoot;
            for(j=0;j<words[i].size();++j){
                if(t->child[words[i][j]-'a']){
                    t=t->child[words[i][j]-'a'];
                    if(t->val!=-1&&t->val!=i&&jgo(words[i], j+1, words[i].size()-1)){
                        tmp[0]=i, tmp[1]=t->val;
                        tans.insert(tmp);
                    }
                }else break;
            }
        }
        for(auto x:tans){
            ans.push_back(x);
        }
        return ans;
    }
};