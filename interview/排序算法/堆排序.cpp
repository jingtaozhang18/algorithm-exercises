#include<bits/stdc++.h>
using namespace std;

// 最小堆
class heap{
    private:
        vector<int> arr;
        int size;
        // 建堆过程
        void build(){
            int i, j, cl, cr, cb;
            for(i=(size-1)>>1;i>=0;--i){ // 从非叶子结点倒序遍历
                j=i;
                while(true){ // 向下处理
                    cb=j, cl=(j<<1)+1, cr=(j<<1)+2;
                    if(cl<size&&arr[cl]<arr[cb]) cb=cl;
                    if(cr<size&&arr[cr]<arr[cb]) cb=cr;
                    if(cb!=j) {swap(arr[j], arr[cb]); j=cb;} 
                    else break;
                }
            }
        }
    public:
        heap():size(0){}
        heap(vector<int>& array):arr(array),size(arr.size()){
            build();
        }
        // pop
        int pop(){
            if(size==0) return -1;
            int res=arr[0];
            swap(arr[0], arr[size-1]);
            --size;
            int j=0,cb,cl,cr;
            while(true){ // 向下处理
                cb=j, cl=(j<<1)+1, cr=(j<<1)+2;
                if(cl<size&&arr[cl]<arr[cb]) cb=cl;
                if(cr<size&&arr[cr]<arr[cb]) cb=cr;
                if(cb!=j) {swap(arr[j], arr[cb]); j=cb;} 
                else break;
            }
            return res;
        }
        // push
        void push(int val){
            if(arr.size()<size) arr[size]=val; 
            else arr.push_back(val);
            ++size;
            int j=size-1, f;
            while(j){
                f=(j-1)>>1;
                if(arr[f]>arr[j]) {swap(arr[j], arr[f]); j=f;}
                else break;
            }
        }
};