// https://leetcode-cn.com/problems/design-hashmap/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int key, value;
    node *next;
    node():next(nullptr){}
    node(int key, int value):key(key),value(value),next(nullptr){}
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    const static int size=197;
    vector<node*> mem;
    MyHashMap():mem(size, nullptr) {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos=key%size;
        auto p=mem[pos];
        while(p){
            if(p->key==key) break;
            p=p->next;
        }
        if(p) p->value=value;
        else{
            p=new node(key, value);
            p->next=mem[pos];
            mem[pos]=p;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos=key%size;
        auto p=mem[pos];
        while(p){
            if(p->key==key) break;
            p=p->next;
        }
        if(p) return p->value;
        else return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int pos=key%size;
        auto p=mem[pos];
        node* f=nullptr;
        while(p){
            if(p->key==key) break;
            f=p;
            p=p->next;
        }
        if(!p) return ;
        if(f){
            f->next=p->next;
            delete p;
        }else{
            mem[pos]=p->next;
            delete p;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */