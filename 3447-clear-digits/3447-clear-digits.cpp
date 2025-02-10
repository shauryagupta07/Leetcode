class Solution {
public:
    string clearDigits(string s) {
       stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]>=48&&s[i]<=57){
                if(!st.empty())st.pop();
            }
            else
                st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            ans.push_back(ch);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};