// https://leetcode-cn.com/problems/implement-trie-prefix-tree/
#include<bits/stdc++.h>
using namespace std;

struct node{
    node* child[26];
    bool valid;
    node(){
        for(int i=0;i<26;++i) child[i]=nullptr;    
        valid=false;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    node* root;
    Trie() {
        root=new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.size()==0) return;
        node* t=root;
        for(auto &e:word){
            if(!t->child[e-'a']) t->child[e-'a']=new node();
            t=t->child[e-'a'];
        }
        t->valid=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* t=root;
        for(auto &e:word){
            if(!t->child[e-'a']) return false;
            t=t->child[e-'a'];
        }
        return t->valid;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* t=root;
        for(auto &e:prefix){
            if(!t->child[e-'a']) return false;
            t=t->child[e-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */