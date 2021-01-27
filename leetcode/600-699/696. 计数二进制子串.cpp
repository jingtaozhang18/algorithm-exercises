// https://leetcode-cn.com/problems/count-binary-substrings/
#include<bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int i, a=0, b=0, ans=0, size=s.size();
        char t=0;
        for(i=0;i<=size;++i){
            if(i<size&&s[i]==t) b++;
            else ans=ans+min(a,b), a=b, b=1, t=s[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
