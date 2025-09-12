class Solution {
public:
    int minOperations(string s) {
        map<char,char>mp;
        for(char c='a';c<='z';c++){
            char mi=123;
            int cnt=0;
            for(int i=0;i<s.length();i++){
                if(s[i]>c&&s[i]<=mi){
                    mi=s[i];
                }
                if(s[i]==c)cnt++;
            }
            if(cnt>0)mp[c]=mi;
        }
        int ans=0;
        for(auto it:mp){
            char ch=it.first;
            char next=it.second;
            if(ch=='a')continue;
            if(ch=='z')ans++;
            else ans+=next-ch;
        }
        return ans;
    }
};