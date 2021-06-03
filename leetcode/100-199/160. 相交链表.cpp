// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a, *b;
        a=headA, b=headB;
        bool fa=true, fb=true;
        while(a&&b&&a!=b){
            if(a->next) a=a->next;
            else if(fa) a=headB, fa=false;
            else return nullptr;
            if(b->next) b=b->next;
            else if(fb) b=headA, fb=false;
            else nullptr;
        }
        return a;
    }
};