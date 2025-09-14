class Solution {
public:
int mod=1e9+7;
int f(int i,int par,int ppar,vector<int>&a,vector<vector<vector<int>>>&dp){
    if(i==a.size()){
        if(par!=2)return 1;
        return 0;
    }

    if(dp[i][par][ppar]!=-1)return dp[i][par][ppar];

    int pick=0,notpick=0;
    if(a[i]%2==0){
        if(par==2){
            pick=f(i+1,0,2,a,dp);
            notpick=f(i+1,2,2,a,dp);
        }
        if(par==0&&ppar==2){
            pick=f(i+1,0,0,a,dp);
            notpick=f(i+1,0,2,a,dp);
        }
        if(par==0&&ppar==0){
            notpick=f(i+1,0,0,a,dp);
        }
        if(par==0&&ppar==1){
            pick=f(i+1,0,0,a,dp);
            notpick=f(i+1,0,1,a,dp);
        }
        if(par==1){
            pick=f(i+1,0,1,a,dp);
            notpick=f(i+1,1,ppar,a,dp);
        }
    }
    else{
        if(par==2){
            pick=f(i+1,1,2,a,dp);
            notpick=f(i+1,2,2,a,dp);
        }
        if(par==1&&ppar==2){
            pick=f(i+1,1,1,a,dp);
            notpick=f(i+1,1,2,a,dp);
        }
        if(par==1&&ppar==1){
            notpick=f(i+1,1,1,a,dp);
        }
        if(par==1&&ppar==0){
            pick=f(i+1,1,1,a,dp);
            notpick=f(i+1,1,0,a,dp);
        }
        if(par==0){
            pick=f(i+1,1,0,a,dp);
            notpick=f(i+1,0,ppar,a,dp);
        }
    }
    return dp[i][par][ppar]=(pick+notpick)%mod;
}
    int countStableSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(3,-1)));
        return f(0,2,2,nums,dp);
    }
};