class Solution {
public:
map<pair<pair<int,int>,pair<int,int>>,int>dp;

int helper(int i,int pro,int sum,int tight,string r){
    if(i==r.length()){
        if(sum==0)return 0;
        if(pro%sum==0)return 1;
        return 0;
    }
    pair<pair<int,int>,pair<int,int>>key={{i,pro},{sum,tight}};
    if(dp.find(key)!=dp.end())return dp[key];
    int ans=0;
     int limit = tight?(r[i]-'0'):9;
    for(int j=0;j<=limit;j++){
        if(sum==0&&j==0)
        ans+=helper(i+1,pro,sum,tight&(limit==j),r);
        else{
        int new_pro=pro*j;
        int new_sum=sum+j;
        if(tight){
            if(r[i]-'0'==j)ans+=helper(i+1,new_pro,new_sum,1,r);
            else ans+=helper(i+1,new_pro,new_sum,0,r);
        }
        else
        ans+=helper(i+1,new_pro,new_sum,0,r);
        }
    }
    return dp[key]=ans;
}
    int beautifulNumbers(int l, int r) {
        string left=to_string(l-1),right=to_string(r);
        int x=helper(0,1,0,1,right);
        dp.clear();
         int y=helper(0,1,0,1,left);
         cout<<x<<" "<<y<<endl;
         return x-y;
    }
};