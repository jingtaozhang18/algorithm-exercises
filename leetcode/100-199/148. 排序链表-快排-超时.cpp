// https://leetcode-cn.com/problems/sort-list/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct no{
    ListNode *head;
    ListNode *pivot;
    ListNode *tail;
};

no partition(ListNode *head, ListNode* tail){ // 左闭右开
    no ans;
    ListNode *a=new ListNode(0), *b=new ListNode(0), *p=head, *ta=a, *tb=b;
    head=head->next;
    while(head!=nullptr&&head!=tail){
        if(head->val<p->val) ta->next=head, ta=ta->next;
        else tb->next=head, tb=tb->next;
        head=head->next;
    }
    if(a->next) ta->next=p, ans.head=a->next;
    else ans.head=p;
    if(b->next) p->next=b->next, tb->next=tail;
    else p->next=tail;
    ans.pivot=p;
    ans.tail=tail;
    return ans;
}

no jsort(ListNode *head, ListNode *tail){
    no ans;
    if(head==nullptr||head->next==tail){
        ans.head = head;
        ans.tail = tail;
        return ans;
    }
    no t=partition(head, tail), a, b;
    if(t.head!=t.pivot){
        a=jsort(t.head, t.pivot);
    }else{
        a.head=t.head, a.tail=t.pivot;
    }
    if(t.pivot->next!=t.tail){
        b=jsort(t.pivot->next, t.tail);
    }else{
        b.head=t.pivot->next;
        b.tail=t.tail;
    }
    if(a.tail) a.tail->next=b.head;
    ans.head=a.head, ans.tail=b.tail;
    return ans;
}



class Solution {
public:
    ListNode* sortList(ListNode* head) {
        no ans = jsort(head, 0);
        return ans.head;
    }
};