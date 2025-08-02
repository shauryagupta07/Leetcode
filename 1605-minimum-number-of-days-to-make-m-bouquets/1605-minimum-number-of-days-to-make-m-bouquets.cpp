class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        int lo=0,hi=*max_element(a.begin(),a.end());
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int cnt=0,total=0;
            for(int i=0;i<a.size();i++){
                if(a[i]<=mid){
                    cnt++;
                }
                else cnt=0;
                if(cnt==k){
                    total++;
                    cnt=0;
                }
            }
            if(total>=m){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};