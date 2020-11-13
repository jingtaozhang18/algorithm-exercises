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

class Solution {
public:
    ListNode* jmerge(ListNode*a, ListNode*b){
        ListNode *t=new ListNode(0), *head=t;
        while(a&&b){
            if(a->val<b->val)t->next=a,t=t->next,a=a->next;
            else t->next=b,t=t->next,b=b->next;
        }
        if(a)t->next=a; if(b)t->next=b;
        return head->next;
    }
    ListNode* jgo(ListNode* head){
        if(!head->next) return head; // 只有一个默认有序
        ListNode*fast=head,*slow=head,*tail=nullptr,*a,*b;
        while(fast->next){
            fast=fast->next; if(fast->next)fast=fast->next;
            tail=slow, slow=slow->next;
        }
        tail->next=nullptr;
        a=jgo(head);
        b=jgo(slow);
        return jmerge(a, b);
    }
    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        return jgo(head);
    }
};