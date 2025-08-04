class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0,el=nums[0];
        for(int i=0;i<nums.size();i++){
            if(freq==0){
                el=nums[i];
            }
            if(nums[i]==el)freq++;
            else freq--;
        }
        return el;
    }
};