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
        if(!head||!head->next) return head;
        ListNode *p=reverseList(head->next); // 到了结尾的位置
        head->next->next=head; // 从尾部开始反转链表
        head->next=nullptr;
        return p;
    }
};