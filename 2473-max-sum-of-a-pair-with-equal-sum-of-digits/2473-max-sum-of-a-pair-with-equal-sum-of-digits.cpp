class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
          int x=nums[i];
          int sum=0;
          while(x){
            int dig=x%10;
            sum+=dig;
            x/=10;
          }
          mp[sum].push_back(nums[i]);
        }
        int ans=-1;
        for(auto it:mp){
          vector<int>v=it.second;
          sort(v.begin(),v.end());
          if(v.size()>=2)ans=max(ans,v[v.size()-1]+v[v.size()-2]);
        }
        return ans;
    }
};