// https://leetcode-cn.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *t=head, *cur;
        while(head&&head->val==val){
            head=head->next;
            delete t;
            t=head;
        }
        if(!head) return head;
        t=head, cur=head->next;
        while(cur){
            if(cur->val==val){
                t->next=cur->next;
                delete cur;
                cur=t->next;
            }else{
                t=cur;
                if(cur) cur=cur->next;
            }
        }
        return head;
    }
};