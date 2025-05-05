class Solution {
public:
#define ll long long
const int mod=1e9+7;
ll f(int i,int j,int n,vector<vector<ll>>&dp){
    if(i>n||j>n)return 0;
    if(i==n&&j==n)return 1;
    if((i==n&&j!=n)||(i!=n&&j==n))return 0;

    if(dp[i][j]!=-1)return dp[i][j];
    ll ans=0;
    
    if(i==j){
        ans=(ans+f(i+1,j+2,n,dp))%mod;
        ans=(ans+f(i+2,j+1,n,dp))%mod;
        ans=(ans+f(i+1,j+1,n,dp)%mod);
    }
    if(j==i-1){
        ans=(ans+f(i+1,j+2,n,dp))%mod;
         ans=(ans+f(i+2,j+3,n,dp))%mod;
    }
    if(i==j-1){
        ans=(ans+f(i+2,j+1,n,dp))%mod;
        ans=(ans+f(i+3,j+2,n,dp))%mod;
    }
    ans=(ans+f(i+2,j+2,n,dp))%mod;
    
    return dp[i][j]=ans;
}
    int numTilings(int n) {
        vector<vector<ll>>dp(n,vector<ll>(n,-1));
        return f(0,0,n,dp);
    }
};