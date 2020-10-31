
// https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
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
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head||head->val==val) return head->next;
        ListNode* t=head;
        for(;t->next;t=t->next) if(t->next->val==val) break;
        if(t->next) t->next=t->next->next;
        return head;
    }
};