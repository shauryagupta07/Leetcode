class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo=0,hi=arr.size()-1;
        int l,dl;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]-mid-1<k){
                l=arr[mid];
                dl=arr[mid]-mid-1;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return l+k-dl;

    }
};