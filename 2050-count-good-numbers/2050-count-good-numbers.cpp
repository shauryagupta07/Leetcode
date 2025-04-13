class Solution {
public:
#define ll long long
const int mod=1e9+7;
ll power(ll a,ll b){
    ll x=1;
    while(b){
        if(b&1)x=((x%mod)*(a%mod))%mod;
        a=((a%mod)*(a%mod))%mod;
        b>>=1;
    }
    return x;
}
    int countGoodNumbers(long long n) {
        ll eve=n/2,odd=n/2;
        if(n%2==1)eve++;
        ll ans=((power(5,eve))%mod*(power(4,odd))%mod)%mod;
        return ans;
    }
};