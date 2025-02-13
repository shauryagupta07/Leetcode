class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<nums.size();i++)pq.push(nums[i]);
        int cnt=0;
        while(pq.size()>=2)
        {
            long long x=pq.top();
            pq.pop();
            if(x>=k)return cnt;
            long long y=pq.top();
            pq.pop();
            long long new_val=2*min(x,y)+max(x,y);
            pq.push(new_val);
            cnt++;
            
        }
        return cnt;
    }
};