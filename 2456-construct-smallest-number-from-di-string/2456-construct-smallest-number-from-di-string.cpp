class Solution {
public:
void f(int i,string &str,string &s,vector<int>&vis,string &pattern){
    if(i==pattern.length()+1){
        bool flag=0;
        for(int j=0;j<pattern.length();j++){
            if(pattern[j]=='I'&&str[j]>=str[j+1]){
                flag=1;
                break;
            }
            if(pattern[j]=='D'&&str[j]<=str[j+1]){
                flag=1;
                break;
            }
        }
        if(flag)return;
        if(str<s)s=str;
        return;
    }
    for(char j='1';j<='9';j++){
        if(vis[j-'1'])continue;
        str.push_back(j);
        vis[j-'1']=1;
        f(i+1,str,s,vis,pattern);
        vis[j-'1']=0;
        str.pop_back();
    }
}
    string smallestNumber(string pattern) {
        vector<int>vis(9,0);
        string s="99999999",str="";
        f(0,str,s,vis,pattern);
        return s;
    }
};