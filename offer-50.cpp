#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
    // 0 初始状态
    // >1 编号
    // -1 出现了重复
    Solution(){
        memset(occ,0,sizeof(occ));
        index=1;
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(occ[ch]==0) occ[ch]=index;
        else if(occ[ch]>=1) occ[ch]=-1;
        ++index;
        // cout<<endl<<occ[ch]<<endl;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int min=10000000;
        int pos=-1;
        for(int i=0;i<256;++i){
            // cout << occ[i] << ' ';
            if(occ[i]>0 && occ[i]<min){
                min=occ[i];
                pos=i;
            }
        }
        // cout<<endl;
        if(pos==-1) return '#';
        return (char)pos;
    }
   int occ[256];
   int index; 
};

int main(){
    string s = "google";
    Solution sol;
    for(int i=0;i<6;++i){
        sol.Insert(s[i]);
        cout<<sol.FirstAppearingOnce();
    }
}