class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                cnt++;
                continue;
            }
            s.insert(nums[i]);
        }
        if(cnt==nums.size()){
            sort(nums.begin(),nums.end());
            return nums[nums.size()-1];
        }
        int ans=0;
        for(auto it:s){
            ans+=it;
        }
        return ans;
    }
};