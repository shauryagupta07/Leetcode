class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        int n=diff.size();
        vector<long long>prefix(n,0);
        prefix[0]=diff[0];
        long long ma=prefix[0],mi=prefix[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+diff[i];
            ma=max(ma,prefix[i]);
            mi=min(mi,prefix[i]);
        }
        int ans=0;
        for(int i=lower;i<=upper;i++){
            if(i+ma<=upper&&i+mi>=lower)ans++;
        }
        return ans;
    }
};