class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>mp;
        int maxi=0;
        for(int i=1;i<=n;i++){
            int div=i;
            int sum=0;
            while(div){
                int rem=div%10;
                sum+=rem;
                div/=10;
            }
            mp[sum]++;
            if(mp[sum]>maxi)maxi=mp[sum];
        }
        int ans=0;
        for(int i=1;i<=36;i++){
            if(mp[i]==maxi)ans++;
        }
        return ans;
    }
};