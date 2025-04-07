class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum&1)return false;
        vector<int>poss(sum+1,false);
        poss[0]=true;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=0;j--){
                if(j-nums[i]>=0&&poss[j-nums[i]])poss[j]=true;
            }
        }
        return poss[sum/2];
    }
};