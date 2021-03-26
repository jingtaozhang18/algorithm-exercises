// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *fh=head, *th=head->next;
        int val=head->val;
        while(th){
            if(th->val==val){
                fh->next=th->next;
                delete th;
                th=fh->next;
            }else{
                val=th->val;
                fh=th, th=th->next;
            }
        }
        return head;
    }
};