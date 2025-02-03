class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int flag=0;
        int maxi=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1])flag=1;
            else if(nums[i]>nums[i+1])flag=0;
            else {
                maxi=max(maxi,1);continue;
            }
            int j=i;
            while(flag==1 && j<n-1 && nums[j]<nums[j+1])j++;
            while(flag==0 && j<n-1 && nums[j]>nums[j+1])j++;
            maxi=max(maxi,j-i+1);
        }
        maxi=max(maxi,1);
        return maxi;
    }
};