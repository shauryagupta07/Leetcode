class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
      map<int,int>mp;
      int n=nums.size();
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          mp[nums[i]*nums[j]]++;
        }
      }
      int ans=0;
      for(auto it:mp){
        int x=it.second;
        if(x>=2){
          ans+=((x*(x-1))/2);
        }
      }
      return ans*8;
    }
};