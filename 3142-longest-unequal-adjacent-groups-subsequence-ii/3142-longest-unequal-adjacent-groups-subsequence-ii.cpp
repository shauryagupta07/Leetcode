class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int>next(words.size(),words.size()),a(words.size(),0);
        int mx=0;
        for(int i=words.size()-1;i>=0;i--){
            int maxi=0;
            for(int j=i+1;j<words.size();j++){
                if((words[i].length()!=words[j].length())||(groups[i]==groups[j]))continue;
                int cnt=0;
                for(int k=0;k<words[j].length();k++){
                    if(words[i][k]!=words[j][k])cnt++;
                }
                if(cnt==1&&maxi<a[j]){
                    next[i]=j;
                    maxi=a[j];
                }
            }
            a[i]=maxi+1;
            mx=max(mx,a[i]);
        }
        vector<string>ans;
        for(int i=0;i<a.size();i++){
            if(a[i]!=mx)continue;
            int j=i;
            while(j<a.size()){
                ans.push_back(words[j]);
                j=next[j];
            }
            break;
        }
        return ans;
    }
};