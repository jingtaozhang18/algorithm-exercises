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