class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            int l=nums[i],mid=nums[i+1],r=nums[i+2];
            if(mid%2==0&&mid/2==(l+r))ans++;
        }
        return ans;
    }
};