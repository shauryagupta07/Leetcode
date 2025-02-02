class Solution {
public:
#define ll long long
ll calc_lcm(ll a,ll b){
  ll lcm=(a*b)/__gcd(a,b);
  return lcm;
}
ll f(int i,int mask,int k,vector<int>&a,map<ll,ll>&mp,vector<vector<int>>&dp){
  if(mask==(1<<k)-1)return 0;

  if(i==a.size()){
    return 1e9;
  }
  if(dp[i][mask]!=-1)return dp[i][mask];
  ll op=1e9;
  for(auto it:mp){
    int new_mask=it.first;
    ll lcm=it.second;
    int nmask=new_mask|mask;
    if(a[i]%lcm!=0){
      ll x=a[i]/lcm;
      op=min(op,lcm*(x+1)-a[i]+f(i+1,nmask,k,a,mp,dp));
    }
    else{
      op=min(op,f(i+1,nmask,k,a,mp,dp));
    }
  }
  return dp[i][mask]=op;
}
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
      int k=target.size();
      int n=nums.size();
      vector<vector<int>>dp(n,vector<int>(1<<k,-1));
      map<ll,ll>mp;
      for(int m=0;m<(1<<k);m++){
        ll lcm=1;
        for(int i=0;i<k;i++){
          if(((m>>i)&1)){
            lcm=calc_lcm(lcm,target[i]);
          }
        }
        mp[m]=lcm;
      }
      return f(0,0,k,nums,mp,dp);
    }
};