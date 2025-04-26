class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        map<int,int>distinct;
        for(int i=0;i<n;i++){
            distinct[nums[i]]++;
        }
        int k=distinct.size();
        int ans=0;
        map<int,int>mp;
        int j=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(j<=i&&mp.size()==k){
                ans+=(n-i);
                mp[nums[j]]--;
                if(mp[nums[j]]==0)mp.erase(nums[j]);
                j++;
            }
        }
        return ans;
    }
};