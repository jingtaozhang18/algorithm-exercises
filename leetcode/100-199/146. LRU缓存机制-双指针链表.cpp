// https://leetcode-cn.com/problems/lru-cache/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
    node* pre;
    node(int val):val(val),next(nullptr),pre(nullptr){}
    node(int val, node*next, node*pre):val(val),next(next),pre(pre){}
};
class LRUCache {
public:
    int cap, size;
    map<int, int> mem; // 内容
    map<int, node*> mp; // key 和节点之间的关联
    node* head;
    node* tail;
    LRUCache(int capacity) {
        cap=capacity;
        size=0;
        head=new node(0);
        tail=head;
    }
    void update(node *n){
        if(tail==n) return; // 已经是最新
        node* fa=n->pre; // 一定存在
        fa->next=n->next; // 更新前一个节点的后向指针
        n->next->pre=fa; // 更新后一个节点的前向指针（不是尾节点，后节点一定存在）
        tail->next=n,n->next=nullptr,n->pre=tail; // 安放目标节点到队尾,更新指针
        tail=n; // 更新队尾指针
    }
    int get(int key) {
        if(mem.find(key)!=mem.end()){
            update(mp[key]); // 提高优先级
            return mem[key];
        }else return -1;
    }
    void put(int key, int value) {
        if(mem.find(key)!=mem.end()){
            update(mp[key]); // 提高优先级
            mem[key]=value;
        }else{
            // 新节点，同时判断是否需要删除
            tail->next=new node(key,nullptr,tail);
            mp[key]=tail->next;
            mem[key]=value;
            // if(!head->next) head->next=tail->next; // 初始化挂载 蔡师弟指出，这是多余的，因为初始化的时候head和tail相等
            tail=tail->next; // 更新tail指针
            size++;
            if(size>cap){
                node*d=head->next; // 要删除的节点
                if(d->next) d->next->pre=head; // 更新前向指针
                // if(d==tail) tail=head; // 更新tail 蔡师弟指出，此项是多余的，容量大于1,没有必要恢复到初始化状态
                head->next=d->next; // 更新后向指针
                mem.erase(mem.find(d->val)); // 更新字典
                mp.erase(mp.find(d->val));
                delete d;
                size--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */