// https://leetcode-cn.com/problems/reverse-linked-list/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*a,*b=nullptr;
        while(head) a=head->next, head->next=b, b=head, head=a;
        return b;
    }
};