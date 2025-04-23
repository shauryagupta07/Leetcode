class Solution {
public:
    #define ll long long
    ll f(int i,int prev,vector<int>&nums,int flag,int x,int k,vector<vector<vector<ll>>>&dp){
        if(i==nums.size()){
            if(flag==2)return 0;
            if(prev==x)return 1;
            if(prev%k==x)return 1;
            return 0;
        }
        if(dp[i][prev][flag]!=-1)return dp[i][prev][flag];
        
        ll take=0,nottake=0;
        
        if(!flag)nottake=f(i+1,prev,nums,0,x,k,dp);
        else{
            ll el=nums[i];
            ll new_prev=(prev*el);
            if(new_prev>k)new_prev=(new_prev)%k;
            take=f(i+1,new_prev,nums,1,x,k,dp);
            if(flag==2)nottake=f(i+1,prev,nums,2,x,k,dp);
            else nottake=f(i+1,prev,nums,0,x,k,dp);
        }
        return dp[i][prev][flag]=take+nottake;
    }
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<ll>res;
        for(int i=0;i<k;i++){
            vector<vector<vector<ll>>>dp(nums.size(),vector<vector<ll>>(k+1,vector<ll>(3,-1)));
            ll ans=f(0,1,nums,2,i,k,dp);
            res.push_back(ans);
        }
        return res;
    }
};