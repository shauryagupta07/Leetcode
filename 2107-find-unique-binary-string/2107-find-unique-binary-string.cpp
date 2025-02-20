class Solution {
public:
void f(string &s,string &ans,int n,int cnt,unordered_map<string,int>&m)
{
    if(cnt==n)
    {
        if(m[s]==0)
        ans=s;
        return;
    }
    s.push_back('1');
    f(s,ans,n,cnt+1,m);
    s.pop_back();
    s.push_back('0');
    f(s,ans,n,cnt+1,m);
    s.pop_back();
}
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int>m;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=1;
        }
        string ans="";
        string s="";
        f(s,ans,n,0,m);
        return ans;
        
    }
};