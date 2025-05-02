class Solution {
public:
    string pushDominoes(string s) {
        int i=0;
        int n=s.length();
        vector<pair<int,int>>segment;
        while(i<s.length()){
            if(s[i]=='.'){
                int l=i,r=i;
                while(s[i]=='.'){
                    r=i;
                    i++;
                }
                segment.push_back({l,r});
            }
            else i++;
        }
        for(int i=0;i<segment.size();i++){
            int l=segment[i].first,r=segment[i].second;
            if(l>0&&r<n-1&&s[l-1]=='R'&&s[r+1]=='L'){
                int mid=(r+l)/2;
                int j=l;
                while(j<mid){
                    s[j]='R';
                    j++;
                }
                if((r-l+1)%2==0)s[mid]='R';
                j=mid+1;
                while(j<=r){
                    s[j]='L';
                    j++;
                }
            }
            else if((l==0||s[l-1]=='L')&&r<n-1&&s[r+1]=='L'){
                int j=l;
                while(j<=r){
                    s[j]='L';
                    j++;
                }
            }
            else if((r==n-1||s[r+1]=='R')&&l>0&&s[l-1]=='R'){
                int j=l;
                while(j<=r){
                    s[j]='R';
                    j++;
                }
            }
        }
        return s;
    }
};