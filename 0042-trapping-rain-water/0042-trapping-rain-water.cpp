class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ma=0;
        vector<int>nge(n),pge(n);
        for(int i=0;i<n;i++){
            
            ma=max(ma,height[i]);
            nge[i]=ma;
        }
        ma=0;
        for(int i=n-1;i>=0;i--){
           
            ma=max(ma,height[i]);
             pge[i]=ma;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int mi=min(nge[i],pge[i]);
            if(mi!=0){
                ans+=mi-height[i];
            }
        }
        return ans;
    }
};