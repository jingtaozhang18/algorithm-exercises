#include<bits/stdc++.h>
using namespace std;

// 最小堆
class heap{
    private:
        vector<int> _arr;
        int _size;
        // 建堆过程
        void build(){
            int i, j, cl, cr, cb;
            for(i=(_size-1)>>1;i>=0;--i){ // 从非叶子结点倒序遍历
                j=i;
                while(true){ // 向下处理
                    cb=j, cl=(j<<1)+1, cr=(j<<1)+2;
                    if(cl<_size&&_arr[cl]<_arr[cb]) cb=cl;
                    if(cr<_size&&_arr[cr]<_arr[cb]) cb=cr;
                    if(cb!=j) {swap(_arr[j], _arr[cb]); j=cb;} 
                    else break;
                }
            }
        }
    public:
        heap():_size(0){}
        heap(vector<int>& array):_arr(array),_size(_arr.size()){
            build();
        }
        // pop
        int pop(){
            if(_size==0) return -1;
            int res=_arr[0];
            swap(_arr[0], _arr[_size-1]);
            --_size;
            int j=0,cb,cl,cr;
            while(true){ // 向下处理
                cb=j, cl=(j<<1)+1, cr=(j<<1)+2;
                if(cl<_size&&_arr[cl]<_arr[cb]) cb=cl;
                if(cr<_size&&_arr[cr]<_arr[cb]) cb=cr;
                if(cb!=j) {swap(_arr[j], _arr[cb]); j=cb;} 
                else break;
            }
            return res;
        }
        // push
        void push(int val){
            if(_arr.size()<_size) _arr[_size]=val; 
            else _arr.push_back(val);
            ++_size;
            int j=_size-1, f;
            while(j){
                f=(j-1)>>1;
                if(_arr[f]>_arr[j]) {swap(_arr[j], _arr[f]); j=f;}
                else break;
            }
        }
        int size(){
            return _size;
        }
};