// https://leetcode-cn.com/problems/throne-inheritance/
#include<bits/stdc++.h>
using namespace std;

struct node{
    string name;
    vector<node*> childs;
    node(string name):name(name){childs=vector<node*>();}
    void addchild(node * c){childs.push_back(c);}
};
class ThroneInheritance {
public:
    node *root;
    unordered_set<string> died;
    unordered_map<string, node*> pos;
    ThroneInheritance(string kingName) {
        root=new node(kingName);
        pos[kingName]=root;
    }
    
    void birth(string parentName, string childName) {
        node *c=new node(childName);
        pos[childName]=c;
        pos[parentName]->addchild(c);
    }
    
    void death(string name) {
        died.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        node *t=root;
        stack<node*> sta;
        stack<int> p;
        vector<string> ans;
        while(t||sta.size()){
            while(t){
                if(died.find(t->name)==died.end()) ans.push_back(t->name);
                if(t->childs.size()){
                    if(t->childs.size()>1){
                        sta.push(t);
                        p.push(1);
                    }
                    t=*(t->childs.begin());
                }else{
                    t=nullptr;
                }
            }
            if(sta.size()){
                t=sta.top()->childs[p.top()];
                if(p.top()+1<sta.top()->childs.size()){
                    p.top()++;
                }else{
                    p.pop();
                    sta.pop();
                }
            }

        }
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */