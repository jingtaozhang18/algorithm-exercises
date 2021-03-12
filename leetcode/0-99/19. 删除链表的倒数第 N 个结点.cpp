// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * fh=new ListNode(0, head);
        ListNode *fast=fh, *slow=fh;
        while(n--) fast=fast->next;
        while(fast->next) fast=fast->next, slow=slow->next;
        fast=slow->next;
        slow->next=fast->next;
        delete fast;
        fast=fh->next;
        delete fh;
        return fast;
    }
};