// https://leetcode-cn.com/problems/closest-dessert-cost/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        set<int> st;
        set<int> tmp;
        int i, j, m=baseCosts.size(), n=toppingCosts.size(), ans_v=INT_MAX, ans;
        tmp.insert(0);
        for(i=0;i<n;++i){
            for(j=0;j<=2;++j){
                for(auto p:tmp){
                    st.insert(p+j*toppingCosts[i]);
                }
            }
            tmp=st;
        }
        for(auto e:baseCosts){
            for(auto p:st){
                int x=p+e;
                int diff=abs(x-target);
                if(diff<ans_v) ans_v=diff, ans=x;
                else if(diff==ans_v) ans=min(ans, x);
            }    
        }
        
//         for(i=0;i<m;++i){
//             int x=target-baseCosts[i];
//             auto p=st.lower_bound(x);
//             if(p!=st.end()){
//                 cout<<"lower"<<baseCosts[i]<<" "<<(*p)<<endl;
//                 int z=abs((*p)+baseCosts[i]-target);
//                 if(z<=ans_v) cout<<(*p)+baseCosts[i]<<endl;
//                 if(z<ans_v) ans_v=z, ans=(*p)+baseCosts[i];
//                 else if(z==ans_v) ans=min((*p)+baseCosts[i], ans);
//             }
            
            
//             p=st.upper_bound(x);
//             if(p!=st.end()){
//                 cout<<"upper"<<baseCosts[i]<<" "<<(*p)<<endl;
//                 int z=abs((*p)+baseCosts[i]-target);
//                 if(z<=ans_v) cout<<(*p)+baseCosts[i]<<endl;
//                 if(z<ans_v) ans_v=z, ans=(*p)+baseCosts[i];
//                 else if(z==ans_v) ans=min((*p)+baseCosts[i], ans);
//             }
//         }
        return ans;
    }
};