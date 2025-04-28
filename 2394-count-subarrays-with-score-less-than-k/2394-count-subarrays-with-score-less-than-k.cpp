class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long j=0;
        long long sum=0;
        long long ans=0;
        for(long long i=0;i<n;i++){
            sum+=nums[i];
            long long x=sum*(i-j+1);

            while(j<=i&&x>=k){
                ans+=(i-j);
                sum-=nums[j];
                j++;
                x=sum*(i-j+1);
            }

        }
        if(sum*(n-j)<k){
            long long l=n-j;
            ans+=(l*(l+1))/2;
        }
        return ans;
    }
};