class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int>st;
        for(int i=0;i<digits.size();i++){
            for(int j=0;j<digits.size();j++){
                for(int k=0;k<digits.size();k++){
                    if(i==j||i==k||j==k||digits[k]%2==1||digits[i]==0)continue;
                    string s="";
                    s.push_back(digits[i]+48);
                    s.push_back(digits[j]+48);
                    s.push_back(digits[k]+48);
                    int num=stoi(s);
                    st.insert(num);
                }
            }
        }
        vector<int>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};