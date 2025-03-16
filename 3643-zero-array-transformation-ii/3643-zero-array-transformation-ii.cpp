class Solution {
public:
    int minZeroArray(vector<int>& a, vector<vector<int>>& q) {
        int n=a.size(),m=q.size();
        int lo=0,hi=m;
        int ans=-1;
        while(lo<=hi){
            int mid=(hi+lo)/2;
            vector<int>prefix(n,0);
            for(int i=0;i<mid;i++){
                int l=q[i][0],r=q[i][1],val=q[i][2];
                prefix[l]-=val;
                if(r+1<n)prefix[r+1]+=val;
            }
            int sum=0;
            bool f=0;
            for(int i=0;i<n;i++){
                sum+=prefix[i];
                int x=a[i]+sum;
                if(x>0)f=1;
            }
            if(!f){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};