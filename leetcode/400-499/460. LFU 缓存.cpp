// https://leetcode-cn.com/problems/lfu-cache/
#include<bits/stdc++.h>
using namespace std;

struct tnode;
struct vnode{
    int val;
    vnode *next, *pre;
    tnode *t;
    vnode(int val):val(val),next(0),pre(0),t(nullptr){};
};

struct tnode{
    int times;
    tnode *next;
    vnode *head, *tail;
    tnode(int times):times(times),next(nullptr),head(nullptr),tail(nullptr){};
};

class LFUCache {
public:
    tnode *HEAD;
    map<int, int> mem; // 记录值
    map<int, int>::iterator mp;
    map<int, vnode*> pos; // 记录位置
    map<int, vnode*>::iterator pp;
    int size;
    int capacity;
    LFUCache(int capacity) {
        HEAD=new tnode(0);
        this->capacity=capacity;
        this->size=0;
    }
    void mountToTail(tnode *tn, vnode *vn){
        // 创建新的时间头
        if(!tn->next) tn->next=new tnode(tn->times+1);
        tn=tn->next;
        // 挂载
        // 设置该节点信息
        vn->pre=tn->tail, vn->next=nullptr, vn->t=tn;
        // 设置时间头和队尾节点的信息
        if(!tn->tail) tn->tail=tn->head=vn;
        else tn->tail->next=vn, tn->tail=vn;
    }
    void deleteHead(tnode *tn){
        // 定位出现次数最少的元素们
        while(tn&&!tn->head) tn=tn->next;
        vnode*vn=tn->head;
        // 只有一个元素
        if(tn->tail==vn) tn->head=tn->tail=nullptr;
        else tn->head=vn->next, vn->next->pre=nullptr;
        // 删除信息
        pos.erase(pos.find(vn->val));
        mem.erase(mem.find(vn->val));
        delete vn;
        // 错误点： 减少size
        this->size--;
    }
    void makeItNew(vnode* node){ // 增加节点的使用次数
        // 在当前次数的队列中取下
        tnode *th=node->t; // 时间头
        // 要删除的是尾元素，更新时间尾信息
        if(th->tail==node) th->tail=node->pre;
        // 要删除的是第一个元素，更新时间头信息
        if(th->head==node) th->head=node->next;
        // 更新节点的前后
        // 错误点：更新的指针有误
        if(node->pre) node->pre->next=node->next;
        if(node->next) node->next->pre=node->pre;
        mountToTail(th, node);
    }
    void show(){
        tnode *tn=HEAD->next; vnode *vn;
        while(tn){
            cout<<"times "<<tn->times<<": ";
            vn=tn->head;
            while(vn){cout<<vn->val<<" "; vn=vn->next;}
            cout<<endl;
            tn=tn->next;
        }
        cout<<endl;
    }
    int get(int key) {
        if((mp=mem.find(key))==mem.end()) return -1;
        makeItNew(pos.find(key)->second);
        // cout<<"get: "<<key<<endl;
        // show();
        return mp->second;
    }
    
    void put(int key, int value) {
        if(!this->capacity) return;
        if((mp=mem.find(key))==mem.end()){ // 新节点
            // 错误点：要先删除，否则加完也删掉了
            if(this->size==capacity) deleteHead(HEAD);
            vnode* vn=new vnode(key);
            mountToTail(HEAD, vn);
            mem[key]=value;
            pos[key]=vn;
            this->size++;
        }else{
            makeItNew(pos.find(key)->second);
            mem[key]=value;
        }
        // cout<<"put: "<<key<<endl;
        // show();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */