#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *a=nullptr, *b=head, *c=head->next; // 必须指定a的值是nullptr;
        while(b){
            b->next=a;
            a=b, b=c;
            if(c) c=c->next;
        }
        return a;
    }
};

int main(void){
    ListNode *head=new ListNode(0), *t=head;
    for(int i=1;i<6;i++){
        t->next = new ListNode(i);
        t=t->next;
    }
    head=Solution().reverseList(head);
    t=head;
    while(t && index){
        cout << t->val <<endl;
        t=t->next;
    }
    return 0;
}