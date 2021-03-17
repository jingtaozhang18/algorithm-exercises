//https://leetcode-cn.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        int i;
        ListNode *th=nullptr, *a=head, *b, *c=nullptr, *ih;
        for(i=1;i<m;++i) th=a,a=a->next; // a反转的开始，th反转前的最后一个
        ih=a; // 记录断开的头
        for(i=m;i<=n;++i){ // a 反转目标，c前一个
            b=a->next,a->next=c,c=a,a=b;
        }
        if(th) th->next=c;
        else head=c;
        ih->next=a;
        return head;
    }
};

// 复习，感觉思路没有第一次做的清晰
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i;
        ListNode *a, *b, *c, *th=head, *tt; // th是前面不动的头，tt是动了的部分的尾巴
        for(i=0;i<left-2&&th;++i) th=th->next;
        if(i<left-2) return head;
        a=nullptr, b=left>1?th->next:th, tt=nullptr; // 特殊处理整个反转的情况
        for(i=0;i<right-left+1&&b;++i){ // 反转元素
            c=b->next;
            b->next=a;
            a=b, b=c;
            if(!tt) tt=a;
        }
        // a是翻转段最后一个，b是后面的头
        if(left>1) th->next=a;
        if(tt) tt->next=b;
        return left>1?head:a;
    }
};