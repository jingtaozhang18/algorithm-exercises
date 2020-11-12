// https://leetcode-cn.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *t=new ListNode(0), *head=t;
        while(l1&&l2){
            if(l1->val<l2->val) t->next=l1, l1=l1->next;
            else t->next=l2, l2=l2->next;
            t=t->next;
        }
        if(l1)t->next=l1;
        if(l2)t->next=l2;
        return head->next;
    }
};