// https://leetcode-cn.com/problems/design-hashset/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *next;
    node(int val):val(val),next(nullptr){}
};
class MyHashSet {
public:
    /** Initialize your data structure here. */
    const int size=193;
    vector<node*> mem;
    MyHashSet():mem(vector<node*>(size, nullptr)) {

    }
    
    void add(int key) {
        int pos=key%size;
        auto p=mem[pos];
        while(p) {if(p->val==key) return; p=p->next;}
        p=new node(key);
        p->next=mem[pos];
        mem[pos]=p;
    }
    
    void remove(int key) {
        int pos=key%size;
        auto p=mem[pos];
        node *f=nullptr;
        while(p){
            if(p->val==key) break; 
            f=p;
            p=p->next;
        }
        if(p) {
            if(f) f->next=p->next; // 判断要删除的是不是头节点
            else mem[pos]=p->next;
            delete p;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos=key%size;
        auto p=mem[pos];
        while(p){
            if(p->val==key) return true;
            p=p->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */