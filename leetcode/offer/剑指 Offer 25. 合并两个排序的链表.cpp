// https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head, *t;
        if(!l1) return l2;
        else if(!l2) return l1;
        else{if(l1->val<l2->val)head=l1,l1=l1->next;else head=l2,l2=l2->next;}
        t=head;
        while(l1&&l2){
            if(l1->val<l2->val){
               t->next=l1;
               l1=l1->next; 
            }else{
                t->next=l2;
                l2=l2->next;
            }
            t=t->next;
        }
        if(l1)t->next=l1;
        if(l2)t->next=l2;
        return head;
    }
};