#include<vector>
using namespace std;
// struct node{
//     int v;
//     node* next=nullptr;
//     node(int v) :v(v){}
// };
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();++i){
            if (nums[i-1]==nums[i]) return true;
        }
        return false;
    }
        
    //     node *mem[1000];
    //     memset(mem,0,sizeof(mem));
    //     for(int v: nums){
    //         int p = v % 1000;
    //         p = max(p,-p);
    //         node *t = mem[p];
    //         if(!t){
    //             mem[p] = new node(v);
    //         }else{
    //             if (t->v==v) return true;
    //             while(t->next){
    //                 if(t->next->v == v) return true;
    //                 t = t->next;
    //             }
    //             t->next = new node(v);
    //         }
    //     }
    //     return false;
    // }
};