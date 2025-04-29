class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
        long long ans=0;
        int n=nums.size();
        int freq=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]==mx)freq++;
            while(freq==k&&j<=i){
                ans+=(n-i);
                if(nums[j]==mx)freq--;
                j++;
            }
        }
        return ans;
    }
};