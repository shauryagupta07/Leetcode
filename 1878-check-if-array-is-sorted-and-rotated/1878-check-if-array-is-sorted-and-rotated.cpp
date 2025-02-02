class Solution {
public:
    bool check(vector<int>& a) {
      int n=a.size();
      int i=0;
        for(;i<n-1;i++){
          if(a[i]>a[i+1]){
            break;
          }
        }
        if(i==n-1)return true;
        i++;
        for(;i<n-1;i++){
          if(a[i]>a[i+1])return false;
        }
        if(a[n-1]<=a[0])return true;
        else return false;
    }
};