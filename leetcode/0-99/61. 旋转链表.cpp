// https://leetcode-cn.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!k) return head;
        int n=0;
        ListNode *t=head, *f, *s;
        while(t) n++, t=t->next;
        k%=n;
        if(!k) return head;
        f=s=head;
        while(k--) f=f->next;
        while(f->next) f=f->next, s=s->next;
        t=s->next, f->next=head, s->next=nullptr;
        return t;
    }
};