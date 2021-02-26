// https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int times;
    node *n, *y;
    node():times(0),n(0),y(0){};
};

void build(node* root, int val){
    int flag=1;
    for(int i=0;i<26;++i){
        if((val&flag)&&!root->y) root->y=new node();
        if(!(val&flag)&&!root->n) root->n=new node();
        if(val&flag) root=root->y;
        else root=root->n;
        flag<<=1;
    }
    root->times++;
}

int find(node* root, int val, int level, int head){
    if(!root) return 0;
    if(level==26) return root->times;
    if(level==head) return find(root->y, val, level+1, head);
    if(val&(1<<level)) return find(root->y, val, level+1, head)+find(root->n, val, level+1, head);
    else return find(root->n, val, level+1, head);
}

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int val, i, flag, size=puzzles.size();
        node *root=new node();
        for(auto e:words){
            val=0;
            for(i=0;i<e.size();++i){
                val=val|(1<<(e[i]-'a'));
            }
            build(root, val);
        }
        vector<int> ans(size);
        for(i=0;i<size;++i){
            val=0;
            for(auto c:puzzles[i]){
                val=val|(1<<(c-'a'));
            }
            ans[i]=find(root, val, 0, puzzles[i][0]-'a');
        }
        return ans;
    }
};