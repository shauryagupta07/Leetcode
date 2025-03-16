class Solution {
public:
    const int p = 31, mod = 1e9 + 7;
    #define ll long long

    vector<int> longestCommonPrefix(vector<string>& a, int k) {
        int n=a.size();
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++){
            string s="";
            int l=a[i].length();
            ll hash=0,p_power=1;
            for(int j=0;j<a[i].length();j++){
               hash += ((a[i][j] - 'a' + 1)%mod * (p_power%mod))%mod;
		       p_power = (p*p_power)%mod;

		       hash %= mod;
		       p_power %= mod;
                mp[{j+1,hash}]++;
            }
        }
        vector<pair<int,pair<int,int>>>v;
        for(auto it:mp){
            int freq=it.second;
            int hash=it.first.second;
            int l=it.first.first;
            if(freq<k)continue;
            v.push_back({l,{freq,hash}});
        }
        int size=v.size();
        vector<int>res(n);
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            map<ll,int>m;
             string s="";
            ll hash=0;
            ll p_power = 1;
            for(int j=0;j<a[i].length();j++){
               hash += ((a[i][j] - 'a' + 1)%mod * (p_power%mod))%mod;
		       p_power = (p*p_power)%mod;

		       hash %= mod;
		       p_power %= mod;
                m[hash]++;
            }
            int ans=0;
            int cnt=0;
            for(int j=size-1;j>=0;j--){
                int x=v[j].second.second;
                int freq=v[j].second.first;
                int l=v[j].first;
                cnt++;
                if(m.find(x)!=m.end()&&freq==k)continue;
                ans=l;
                break;
            }
            res[i]=ans;
        }
        return res;
    }
};