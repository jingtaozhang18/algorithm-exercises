class Solution {
public:
    int mod = 1e9+7;
    unordered_map<int, long long> mem;
    long long jgo(long long val, int times){ // 需要快速幂的支持
        if(times==1) return val;
        else if(times==0) return 1;
        else if(mem.find(times)!=mem.end()) return mem[times];
        else return mem[times]=(jgo(val, times/2)*jgo(val, times-times/2))%mod;
    }

    int maxNiceDivisors(int primeFactors) {
        if(primeFactors<3) return primeFactors;
        long long ans=1, mod=1e9+7;
        int a = primeFactors / 3;
        int b = primeFactors % 3;
        if(b==1) a--, b=4;
        else if(b==0) b=1;
        ans=jgo(3, a);
        ans*=b, ans%=mod;
        return ans;
    }
};