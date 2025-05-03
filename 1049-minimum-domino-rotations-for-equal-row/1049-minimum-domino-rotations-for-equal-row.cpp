class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans=1e9;
        for(int i=1;i<=6;i++){
            int cnt1=0,cnt2=0;
            for(int j=0;j<tops.size();j++){
                if(tops[j]==i)continue;
                if(bottoms[j]==i)cnt1++;
                else{
                    cnt1=1e9;
                    break;
                }
            }
            for(int j=0;j<tops.size();j++){
                if(bottoms[j]==i)continue;
                if(tops[j]==i)cnt2++;
                else{
                    cnt2=1e9;
                    break;
                }
            }
            ans=min(ans,min(cnt1,cnt2));
        }
        if(ans==1e9)return -1;
        return ans;
    }
};