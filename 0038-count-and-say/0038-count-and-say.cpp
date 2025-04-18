class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int i=2;i<=n;i++){
            string temp="";
            int cnt=1;
            for(int j=1;j<s.length();j++){
                if(s[j]==s[j-1])cnt++;
                else{
                    string count=to_string(cnt);
                    temp+=count;
                    temp.push_back(s[j-1]);
                    cnt=1;
                }
            }
            string count=to_string(cnt);
            temp+=count;
            temp.push_back(s[s.length()-1]);
            s=temp;
        }
        return s;
    }
};