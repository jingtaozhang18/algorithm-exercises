// 详细描述
// 判断一个包含通配符的字符串是否能完全匹配另一个字符串：

// - ’?’表示匹配任意一个字符一次，如a?c匹配abc；

// - ’#’表示匹配任意一个字符零次或一次，如a#c匹配ac和abc；

// - ’*’表示匹配任意字符零次或者任意多次，如a*c匹配ac、abc和abbbbc；

// - 其他字符匹配原字符

 

// 注意：不允许使用任何正则表达式库

// 其他
// 时间限制: 1000ms

// 内存限制: 256.0MB


#include<bits/stdc++.h>
using namespace std;

bool judge(string &a, string &b, int i, int j){
    int m=a.size(), n=b.size();
    if(i==m&&j==n) return true; // 
    if(i==m&&j<n) return false;
    // i一定不到头
    if(a[i]!='#'&&a[i]!='*'){
        if(j==n) return false;
        if(a[i]=='?'||a[i]==b[j]) return judge(a, b, i+1, j+1);
    }else{ // 特殊字符匹配
        if(a[i]=='#') {
            if(judge(a, b, i+1, j)) return true;
            if(judge(a, b, i+1, j+1)) return true;
        }
        if(a[i]=='*'){
            if(judge(a, b, i+1, j)) return true;
            if(judge(a, b, i+1, j+1)) return true;
            for(int k=j+1;k<n&&b[k-1]==b[k];++k) if(judge(a, b, i+1, k+1)) return true;
        }
    }
    return false;
}



int main(void){
    string a, b;
    cin>>a>>b;
    cout<<(judge(a, b, 0, 0)?"1":"0")<<endl;
    return 0;
}