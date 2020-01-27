#include<string>
using namespace std;

struct node{
    char c;
    bool eff=false;
    node *next[26] = {nullptr}; // 快速初始化，不要使用memset函数进行初始化
    node(char c) : c(c) {};
    node() : c(0) {};
    
};
class Trie {
public:
    /** Initialize your data structure here. */
    node* root;
    
    Trie() {
        root = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node *t = root;
        for(char c : word){
            if( t->next[c-'a'] == nullptr){
                t->next[c-'a'] = new node(c);
            }
            t = t->next[c-'a'];
        }
        t->eff = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *t = root;
        for(char c : word){
            if(!t->next[c-'a']) return false;
            t = t->next[c-'a'];
        }
        return t->eff;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node *t = root;
        for(char c : prefix){
            if(!t->next[c-'a']) return false;
            t = t->next[c-'a'];
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