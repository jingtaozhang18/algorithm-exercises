// 给定一个链表，每两个节点之间反转一次，返回反转后的头节点
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
    node(int val):val(val){next=nullptr;}
};
// 第一版做法
node* func(node* head){
    node* pre, * x, *y, *z, new_head;
    pre=nullptr;
    x=head;
    if(!x) return nullptr;
    y=x->next;
    if(!y) return head;
    new_head=nullptr;
    while(x&&y){
        z=y->next;
        if(pre) pre->next=y;
        pre=x;
        if(!new_head) new_head=y;
        y->next=x;
        x->next=z;
        x=z;
        if(z) y=x->next;
        else y=nullptr;
    }
    return new_head;
}

// 要求省略一个临时变量
node* func2(node* head){
    node* pre, *x, *z, new_head;
    pre=nullptr;
    x=head;
    if(!x) return nullptr;
    if(!x->next) return head;
    new_head=nullptr;
    while(x&&x->next){
        z=x->next->next;
        if(pre) pre->next=x->next;
        pre=x;
        if(!new_head) new_head=x->next;
        x->next->next=x;
        x->next=z;
        x=z;
    }
    return new_head;
}

