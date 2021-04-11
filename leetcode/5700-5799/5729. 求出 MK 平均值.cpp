// https://leetcode-cn.com/contest/weekly-contest-236/problems/finding-mk-average/
#include<bits/stdc++.h>
using namespace std;

class MKAverage {
public:
    int m, k;
    multiset<int> sta, stb, stc;
    queue<int> que;
    long long sum;
    MKAverage(int m, int k) {
        this->m=m-2*k, this->k=k;
        sum=0;
        // cout<<this->m<<this->k<<endl;
    }
    
    void addElement(int num) {
        // cout<<"add"<<num<<endl;
        int x;
        que.push(num);
        if(que.size()>(m+2*k)) {
            if(sta.find(que.front())!=sta.end()){
                sta.erase(sta.find(que.front()));
            }else if(stc.find(que.front())!=stc.end()){
                stc.erase(stc.find(que.front())); // 错误点，erase(val) 会删掉所有相同的值
            }else{
                stb.erase(stb.find(que.front()));
                sum-=que.front();
                if(sta.size()){  // 错误点，若sta，stc有元素，那么stb必须有元素
                    auto p=sta.end();
                    --p;
                    x=*p;
                    stb.insert(*p);
                    sum+=*p;
                    sta.erase(p);
                }
                if(stc.size()){
                    auto p=stc.begin();
                    x=*p;
                    stb.insert(*p);
                    sum+=*p;
                    stc.erase(p);
                }
            }
            que.pop();
        }
        
        auto p=stb.end(); if(stb.size()) --p; // 错误点 stb.size()==0的时候，指针--操作会出错
        if(stb.size()>=m&&num<*(stb.begin())) sta.insert(num);
        else if(stb.size()>=m&&num>*p) stc.insert(num);
        else {stb.insert(num); sum+=num;} //  cout<<"add++"<<num<<endl;}
        
        if(que.size()==m+2*k){
            // cout<<"fc"<<stb.size()<<endl;
            while(sta.size()>k){ // 错误点，需要处理sta，stb的元素数量过多的情况
                auto p=sta.end();
                --p;
                x=*p;
                stb.insert(*p);
                sum+=*p;
                sta.erase(p);
            }
            while(stc.size()>k){
                auto p=stc.begin();
                x=*p;
                stb.insert(*p);
                sum+=*p;
                stc.erase(p);
            }
            while(stb.size()>m){
                if(sta.size()>stc.size()){
                    auto p=stb.end();
                    --p;
                    x=*p;
                    stc.insert(*p);
                    sum-=*p;
                    stb.erase(p);
                }else{
                    auto p=stb.begin();
                    sta.insert(*p);
                    x=*p;
                    sum-=*p;
                    stb.erase(p);
                }
                // cout<<"--"<<x<<endl;
            }
        }
        // cout<<"sum"<<sum<<endl;
    }
    
    int calculateMKAverage() {
        if(que.size()<m+2*k) return -1;
        return sum/m;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */