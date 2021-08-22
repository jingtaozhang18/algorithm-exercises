// https://leetcode-cn.com/problems/delete-middle-node-lcci/
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
    void deleteNode(ListNode* node) {
        ListNode *ln=node->next, *f;
        while(ln) node->val=ln->val, f=node, ln=ln->next, node=node->next;
        f->next=nullptr;
        delete node;
    }
};