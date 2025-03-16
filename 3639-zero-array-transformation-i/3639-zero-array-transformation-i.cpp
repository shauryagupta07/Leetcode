class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>prefix(n,0);
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0],r=queries[i][1];
            prefix[l]--;
            if(r+1<n)prefix[r+1]++;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=prefix[i];
            nums[i]+=sum;
            if(nums[i]>0)return false;
        }
        return true;
    }
};