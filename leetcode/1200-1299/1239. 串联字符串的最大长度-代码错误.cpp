// https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
class Solution {
public:
    int jgen(string& s){
        int ans=0;
        for(auto &c:s) 
            if(1<<(c-'a') & ans) return -1; 
            else ans|=1<<(c-'a');
        return ans;
    }
    int maxLength(vector<string>& arr) {
        unordered_map<int, int> mpa;
        int k, x;
        int ans=0;
        for(auto &s:arr){
            unordered_map<int, int> mpb=mpa;
            k=jgen(s);
            if(k==-1) continue;
            for(auto p:mpb){
                if(!(p.first&k)){
                    x=p.first|k;
                    auto sp=mpb.find(x);
                    if(sp!=mpa.end()) mpa[x]=max(sp->second, s.size()+p.second);
                    else mpa[x]=max(sp->second, s.size()+p.second);
                    ans=max(mpa[x], ans);
                }
            }
             auto sp=mpa.find(x);
             if(sp==mpa.end()) mpa[k]=s.size();
             else mpa[k]=max(s.size(), sp->second);
             ans=max(mpa[k], ans);
        }
        return ans;
    }
};

int main(){
    vector<string> input{"un","iq","ue"};
    cout<<Solution().maxLength(input)<<endl;
}