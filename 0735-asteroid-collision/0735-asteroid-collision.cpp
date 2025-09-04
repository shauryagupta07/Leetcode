class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        for(int i=0;i<a.size();i++){
            if(a[i]<0){
                while(!st.empty()&&a[st.top()]<abs(a[i])){
                    a[st.top()]=0;
                    st.pop();
                }
                if(!st.empty()&&a[st.top()]==abs(a[i])){
                    a[i]=0;
                    a[st.top()]=0;
                }
                else if(!st.empty()){
                    a[i]=0;
                }
                
            }
            else st.push(i);
        }
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            if(a[i]!=0)ans.push_back(a[i]);
        }
        return ans;
    }
};