class Solution {
public:
#define ll long long
    long long countGood(vector<int>& a, int k) {
        map<int,int>mp;
        int n=a.size();
        ll sum1=0,sum2=0;
        ll ans=0;
        int j=0;
        for(int i =0;i<n;i++){
            while(j<n&&(sum1-sum2)/2<k){
                int f=mp[a[j]];
                sum2++;
                sum1-=(f*f);
                sum1+=((f+1)*(f+1));
                mp[a[j]]++;
                j++;
            }
            //cout<<(sum1-sum2)/2<<endl;
            if((sum1-sum2)/2>=k)ans+=(n-j+1);
            int f=mp[a[i]];
            sum1-=(f*f);
            sum1+=((f-1)*(f-1));
            sum2--;
            mp[a[i]]--;
        }
        return ans;
    }
};