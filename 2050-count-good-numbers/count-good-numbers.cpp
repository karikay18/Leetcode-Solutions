class Solution {
    const long long mod = 1000000007;
public:
    long long solve(long long x, long long y)
    {
        if(y==0)return 1;
        long long ans=solve(x,y/2);
        ans*=ans;
        ans%=mod;
        if(y%2)ans*=x;
        ans%=mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even = (n/2)+(n%2);
        return (solve(5,even)*solve(4,odd))%mod;
    }
};