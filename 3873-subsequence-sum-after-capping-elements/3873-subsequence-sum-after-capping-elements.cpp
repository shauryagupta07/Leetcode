class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        unordered_set<int>s;
        s.insert(0);
        int prev=0;
        vector<bool>res;
        for(int x=1;x<=a.size();x++){
            int lb=lower_bound(a.begin(),a.end(),x)-a.begin();
            vector<int>v;
            for(int j=prev;j<lb;j++){
                for(auto it:s){
                    if(it+a[j]<=k&&s.find(it+a[j])==s.end())v.push_back(it+a[j]);
                }
                for(auto it:v){
                    s.insert(it);
                }
            }
            
            bool ans=false;
            int x_count=a.size()-lb;
            for(auto it:s){
                if((k-it)%x==0&&(k-it)/x<=x_count)ans=true;
            }
            res.push_back(ans);
            prev=lb;
        }
        return res;
    }
};