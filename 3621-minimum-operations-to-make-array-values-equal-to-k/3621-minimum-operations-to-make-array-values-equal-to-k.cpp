class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]<k)return -1;
        map<int,int>mp;
        int j=-1;
        for(int i=n-1;i>=0;i--){
            mp[nums[i]]++;
            if(mp.size()==2){
                j=i;
                break;
            }
        }

        set<int>s;
        for(int i=0;i<=j;i++){
            s.insert(nums[i]);
        }
        if(nums[0]==k)return s.size();
        else return s.size()+1;
    }
};