class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        //lx xl
        //cc cc
        //xx xx xx xx xx
        //cx xc xc cx 
        //ll ll
        map<string,int>mp;
        int fl=0;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        int ans=0;
        for(auto it:mp){
            string cur=it.first;
            int cnt1=it.second;
            string rev=cur;
            reverse(rev.begin(),rev.end());
            int cnt2=mp[rev];
            if(rev==cur&&fl==0){
                ans+=2*cnt1;
                if(cnt1%2==1)
                fl=1;
            }
            else if(rev==cur&&fl==1){
                if(cnt1%2==0)ans+=2*cnt1;
                else ans+=2*(cnt1-1);
            }
            else
            ans+=2*min(cnt1,cnt2);
        }
        if(ans==0)return ans;
        return ans;
    }
};