class Solution {
public:
    int f(int i,int sum,vector<int>&b,vector<vector<int>>&dp){
        if(sum==0)return 1;
        if(i==b.size())return 0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        int nottake=f(i+1,sum,b,dp);
        int take=0;
        if(sum>=b[i])take=f(i+1,sum-b[i],b,dp);
        return dp[i][sum]=take|nottake;
    }
    int minZeroArray(vector<int>& a, vector<vector<int>>& queries) {
        int n=a.size();
        vector<vector<int>>v(n);
        int ans=-1;
        int lo=0,hi=queries.size();
        while(lo<=hi){
            int mid=(lo+hi)/2;
            vector<vector<int>>b(n);
        for(int i=0;i<mid;i++){
            int l=queries[i][0],r=queries[i][1],val=queries[i][2];
            for(int j=l;j<=r;j++){
                b[j].push_back(val);
            }
        }
            bool flag=0;
            for(int i=0;i<n;i++){
                vector<vector<int>>dp(b[i].size(),vector<int>(a[i]+1,-1));
                if(!f(0,a[i],b[i],dp)){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};