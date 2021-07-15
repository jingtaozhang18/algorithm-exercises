#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct node{
    int val;
    node* next;
    node(int val):val(val), next(nullptr){};
};

struct pos{
    node *head;
    node *pivot;
    node *tail;
};

pos patition(node* head, node* tail){
    // cout<<"\tpartition: "<<head->val<<"\t";
    // if(tail) cout<<tail->val<<"\t";
    // else cout<<"none"<<"\t";
    node *a=new node(0), *b=new node(0), *p, *ta=a, *tb=b;
    pos ans;
    if(head==tail) {
        ans.head=head, ans.pivot=head, ans.tail=head;
        return ans;
    }

    p=head;
    head=head->next;

    while(head!=nullptr&&head!=tail){
        if(head->val<p->val) ta->next=head, ta=ta->next;
        else tb->next = head, tb=tb->next;
        head=head->next;
    }

    if(a->next) ta->next=p, ans.head=a->next;
    else ans.head=p;

    if(b->next) p->next=b->next, tb->next=tail;
    else p->next=tail;

    ans.pivot=p;
    ans.tail=tail;

    // cout<<ans.head->val<<"\t"<<ans.pivot->val<<"\t";
    // if(ans.tail) cout<<ans.tail->val<<endl;
    // else cout<<endl;
    
    return ans;
}


pos sort(node* head, node *tail){
    pos ans;
    ans.head = head;
    ans.tail = tail;
    if(head==0||head->next==tail) return ans; // 只有一个元素

    // cout<<"sort: "<<head->val<<"\t";
    // if(tail)cout<<tail->val<<"\t";
    // else cout<<"none"<<"\t";
    
    pos t = patition(head, tail);
    pos a,b;
    if(t.head!=t.pivot)
        a = sort(t.head, t.pivot);
    else {
        a.head=t.head;
        a.tail=t.pivot;
    }
    if(t.pivot->next!=t.tail)
        b = sort(t.pivot->next, t.tail);
    else{
        b.head=t.pivot->next;
        b.tail=t.tail;
    }
    // cout<<"ans: \t"<<a.head->val;//<<" "<<b.head->val;
    if(a.tail) a.tail->next=b.head;
    ans.head=a.head; ans.tail=b.tail;
    return ans;
}


int main() {
    node *head=new node(0), *t=head;
    for(int i=0;i<30;++i){
        t->next=new node(rand());
        t=t->next;
    }
    head=head->next;
    t=head;
    cout<<"input: ";
    while(t) {cout<<t->val<<" "; t=t->next;}
    cout<<endl;

    pos ans = sort(head, 0);
    t=ans.head;
    cout<<"output: ";
    while(t) {cout<<t->val<<" "; t=t->next;}

}