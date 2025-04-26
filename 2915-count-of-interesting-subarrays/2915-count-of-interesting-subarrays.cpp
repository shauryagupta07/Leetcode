class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        vector<int>prefix(n,0);
        map<int,int>mp;
        long long ans=0;
        mp[0]++;
        if(nums[0]%modulo==k)prefix[0]=1;
        for(int i=1;i<n;i++){
            int rem=nums[i]%modulo;
            if(rem==k)prefix[i]=prefix[i-1]+1;
            else prefix[i]=prefix[i-1];
        }
        for(int i=0;i<n;i++){
            prefix[i]=prefix[i]%modulo;
            if(k==0){
                ans+=mp[prefix[i]];
            }
            else{
                ans+=mp[prefix[i]+modulo-k];
                ans+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};