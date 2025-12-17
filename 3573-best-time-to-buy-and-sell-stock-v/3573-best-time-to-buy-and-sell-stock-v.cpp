class Solution {
public:
long long f(int i,int k,int f1,vector<int>&prices,vector<vector<vector<long long>>>&dp){
    if(k==0)return 0;
    if(i==prices.size()){
        if(f1==0)return 0;
        else return -1e15;
    }

    if(dp[i][k][f1]!=-1)return dp[i][k][f1];

    if(f1==0){
        long long take1=-prices[i]+f(i+1,k,1,prices,dp);
        long long take2=prices[i]+f(i+1,k,2,prices,dp);
        long long nottake=f(i+1,k,0,prices,dp);
        return dp[i][k][f1]=max(max(take1,take2),nottake);
    }
    else if(f1==1){
        long long take=prices[i]+f(i+1,k-1,0,prices,dp);
        long long nottake=f(i+1,k,1,prices,dp);
        return dp[i][k][f1]=max(take,nottake);
    }
    else{
        long long take=-prices[i]+f(i+1,k-1,0,prices,dp);
        long long nottake=f(i+1,k,2,prices,dp);
        return dp[i][k][f1]=max(take,nottake);
    }
}
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(k+1,vector<long long>(3,-1)));
        return f(0,k,0,prices,dp);
    }
};