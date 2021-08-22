// https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *t,*fhead=head,*a,*b;
        while(head){
            t=head->next;
            head->next=new Node(head->val);
            head->next->next=t;
            head->next->random=head->random;
            head=t;
        }
        t=fhead->next;
        while(t){
            if(t->random) t->random=t->random->next;
            if(t->next) t=t->next->next;
            else t=NULL;
        }
        head=fhead->next, t=fhead;
        while(t){
            a=t->next;
            b=t->next->next;
            t->next=b;
            if(b)a->next=b->next;
            t=b;
        }
        return head;
    }
};