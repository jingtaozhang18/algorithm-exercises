#include<vector>
#include<iostream>
using namespace std;

int GetNumberOfK(vector<int> data ,int k) {
    // 二分查找的加强版
    int start=0,end=data.size()-1,index=(start+end)>>1;
    if (end<0) return 0;
    // 寻找左边界
    while(start<end){
        if(data[index]==k){
            if(index>start && data[index-1]==k){
                end=index-1;
            }
            else break;
        }else if(data[index]<k){
            // 向右寻找
            start=index+1;
        }else if(data[index]>k){
            // 向左寻找
            end=index-1;
        }
        index=(start+end)>>1;
    }
    if(data[index]!=k) return 0;
    int left=index;
    // 寻找右边界
    start=0,end=data.size()-1,index=start+((start+end)>>1);
    while(start<end){
        if(data[index]==k){
            if(index<end && data[index+1]==k){
                start=index+1;
            }
            else break;
        }else if(data[index]<k){
            // 向右寻找
            start=index+1;
        }else if(data[index]>k){
            // 向左寻找
            end=index-1;
        }
        index=(start+end)>>1;
    }
    cout <<left <<" "<<index<<endl;
    return index-left+1;
}

int main(){
    int len,tep;
    vector<int> input;
    cin>>len;
    while(len--) { cin>>tep; input.push_back(tep); }
    cout << endl << GetNumberOfK(input, 4)<<endl;
}