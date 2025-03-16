class Solution {
public:
    vector<int> solveQueries(vector<int>& a, vector<int>& queries) {
        int n=a.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[a[i]].push_back(i);
        }
        vector<int>dist(n);
        for(auto it:mp){
            vector<int>v=it.second;
                int val=it.first;
            for(int i=0;i<v.size()-1;i++){
                int mi=1e9;
                if(i==0){
                    mi=abs(n-v[v.size()-1]+v[i]);
                }
                else if(i>0)mi=abs(v[i-1]-v[i]);
                mi=min(mi,abs(v[i]-v[i+1]));
                if(mi==1e9)dist[v[i]]=-1;
                else
                dist[v[i]]=mi;
            }
            //cout<<dist[0]<<endl;
            int x=v.size()-1;
            if(x>0)dist[v[x]]=min(abs(n-v[x]+v[0]),abs(v[x]-v[x-1]));
            else dist[v[x]]=-1;
        }
        cout<<endl;
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i]=dist[queries[i]];
        }
        return ans;
    }
};