class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>mp;
        for(int i=0;i<dominoes.size();i++){
            int a=dominoes[i][0],b=dominoes[i][1];
            mp[{min(a,b),max(a,b)}]++;
        }
        int ans=0;
        for(auto it:mp){
            int x=it.second;
            ans+=(x*(x-1))/2;
        }
        return ans;
    }
};