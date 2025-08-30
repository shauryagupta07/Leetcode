class Solution {
public:
//MISINTERPRETED THE QUES AS ---->""NUMBER OF SUBARRAYS WITH MAXIMUM OR"", THOUGH DID THAT ALSO USING BINARY SEARCH


    // int calc(vector<int>v){
    //     int ans=0;
    //     for(int i=0;i<v.size();i++){
    //         if(v[i]>0)ans+=pow(2,i);
    //     }
    //     return ans;
    // }
    void f(int i,int mx,int val,int &ans,vector<int>&a){
        if(i==a.size()){
            if(val==mx)ans++;
            return;
        }
        f(i+1,mx,val|a[i],ans,a);
        f(i+1,mx,val,ans,a);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or=0;
        for(int i=0;i<nums.size();i++){
            max_or=max_or|nums[i];
            int x=nums[i];
           
        }
        int ans=0;
        if(max_or==0)ans--;
        f(0,max_or,0,ans,nums);
        return ans;
      
        // for(int i=0;i<nums.size();i++){
          
        //     int lo=i,hi=nums.size()-1;
        //     int ind=nums.size();
        //     while(lo<=hi){
        //         int mid=(lo+hi)/2;
        //         vector<int>left(32,0);
        //         for(int j=0;j<32;j++){
        //             if(i>0){
        //                 left[j]=prefix[mid][j]-prefix[i-1][j];
        //             }
        //             else left[j]=prefix[mid][j];
        //         }
        //         int val=calc(left);
        //         if(val<max_or){
        //             lo=mid+1;
        //         }
        //         else{
        //             ind=mid;
        //             hi=mid-1;
        //         }
        //     }
        //     cout<<i<<" "<<ind<<endl;
        //     ans+=(nums.size()-ind);
        // }
        // return ans;
    }
};