// https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
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
    ListNode* reverseList(ListNode* head) {
        ListNode *last=nullptr, *t=nullptr;
        while(head){
            last=t, t=head, head=head->next;
            t->next=last;
        }
        return t;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *a=nullptr, *b=head, *c;
        while(b){
            c=b->next;
            b->next=a;
            a=b, b=c;
        }
        return a;
    }
};