// https://leetcode-cn.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int j=0, v;
        ListNode *t=new ListNode(), *head=t;
        while(l1||l2||j){
            v=j+(l1?l1->val:0)+(l2?l2->val:0);
            t->next=new ListNode(v%10), j=v/10;
            t=t->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        return head->next;
    }
};