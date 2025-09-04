class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>a;
        vector<int>nge(nums.size());
        for(int i=0;i<nums.size();i++)a.push_back(nums[i]);
        for(int i=0;i<nums.size();i++)a.push_back(nums[i]);
        for(int i=0;i<a.size();i++){
            while(!st.empty()&&a[st.top()]<a[i]){
                nge[st.top()]=a[i];
                st.pop();
            }
            if(i<nums.size())st.push(i);
        }
        while(!st.empty()){
            nge[st.top()]=-1;
            st.pop();
        }
        return nge;
    }
};