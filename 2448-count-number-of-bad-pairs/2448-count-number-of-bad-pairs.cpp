class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long total=0;
        long long n=nums.size();
        map<long long,long long>mp;
        for(int i=0;i<n;i++){
          mp[nums[i]-i]++;
        }
        for(auto it:mp){
          long long x=it.second;
          total+=(x*(x-1))/2;
        }
        long long all=(n*(n-1))/2;
        return all-total;
    }
};