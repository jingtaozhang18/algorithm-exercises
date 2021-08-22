// https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
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
        ListNode *a=headA, *b=headB;
        while(a!=b){
            a=a?a->next:headB;
            b=b?b->next:headA;
        }
        return a;
    }
};

// 复习
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA, *b=headB;
        bool ba=true, bb=true;
        while(a&&b){
            if(a==b) return a;
            if(a->next) a=a->next;
            else{
                if(ba) a=headB, ba=false;
                else a=nullptr;
            }
            if(b->next) b=b->next;
            else{
                if(bb) b=headA, bb=false;
                else b=nullptr;
            }
        }
        return nullptr;
    }
};
