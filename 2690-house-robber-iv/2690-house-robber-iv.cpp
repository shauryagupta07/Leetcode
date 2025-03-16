class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int lo=0,hi=*max_element(nums.begin(),nums.end());
        int ans;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int i=0;
            int cnt=0;
            while(i<n){
                if(nums[i]<=mid){
                    cnt++;
                    i+=2;
                }
                else i++;
            }
            if(cnt>=k){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};