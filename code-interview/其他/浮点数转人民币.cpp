// https://www.nowcoder.com/questionTerminal/00ffd656b9604d1998e966d555005a4b
#include<bits/stdc++.h>
using namespace std;

// 暂存  TODO
string mapa[]{"壹","贰","叁","肆","伍","陆","柒","捌","玖"};
string mapb[]{"","拾","佰","仟"};

string funca(vector<int>& val){ // 四位数字为一个轮
    int i;
    string ans="";
    for(i=3;i>=0;--i){
        if(val[i]) {
            if(i+1<4&&val[i+1]==0){
                ans.append("零");
            }
            ans.append(mapa[val[i]]+mapb[i]);
        }
    }
}

int main(void){
    double val;
    cin>>val;
    long long a=(long long)val; // 整数
    long long b=(long long)val*100-a*100; // 小数
    vector<vector<int>> vals;
    int i=0;
    while(a){
        if(i%4==0) vals.push_back(vector<int>(4));
        vals[i/4][i%4]=a%10;
        a/=10;
        ++i;
    }
    string t;
    string ans="";
    for(i=vals.size()-1;i>=0;--i){
        t=funca(vals[i]);
        ans.append(t+mapb[i]);
    }
    cout<<ans<<endl;
    return 0;
}