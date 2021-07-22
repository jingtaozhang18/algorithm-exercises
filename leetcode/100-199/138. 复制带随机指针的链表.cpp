// https://leetcode-cn.com/problems/copy-list-with-random-pointer/
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node *t=head, *next, *ans, *x;
        while(t){
            next=t->next;
            t->next=new Node(t->val);
            t->next->random=t->random;
            t->next->next=next;
            t=next;
        }
        t=head;
        while(t){
            t->next->random=t->random?t->random->next:nullptr;
            t=t->next->next;
        }
        ans=head->next, t=head, x=head->next;
        while(t){
            t->next=x->next;
            t=x?x->next:nullptr;
            x->next=t?t->next:nullptr;
            x=t?t->next:nullptr;
        }
        return ans;
    }
};