// https://leetcode-cn.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *ans=nullptr, *tail=nullptr, *f=head, *t=head->next;
        while(t){
            if(!ans) ans=t;
            f->next = t->next;
            t->next = f;
            if(tail) tail->next=t;
            tail=f, f=f->next;
            if(f) t=f->next;
            else t=nullptr;
        }
        return ans;
    }
};