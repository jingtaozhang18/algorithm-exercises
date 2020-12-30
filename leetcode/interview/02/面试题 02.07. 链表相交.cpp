// https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/
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
        bool fa=false, fb=false;
        if(!a||!b) return nullptr; // 错误点： 初始化的判断
        while(true)
        {
          if(a==b) return a;
          if(a->next) a=a->next;
          else 
          {
            if(fa&&fb) return nullptr;
            fa=true, a=headB;
          }
          if(b->next) b=b->next;
          else 
          {
            if(fa&&fb) return nullptr;
            fb=true, b=headA;
          }
        }
    }
};