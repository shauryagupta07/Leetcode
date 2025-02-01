class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        map<int,int>mp;
        
        for(int i=0;i<n;i++){
            if(i==0){
                mp[startTime[i]]++;
            }
            else mp[startTime[i]-endTime[i-1]]++;
            if(i==n-1){
                mp[eventTime-endTime[i]]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int start=startTime[i];
            int end=endTime[i];
            if(i==0){
                mp[start]--;
                if(mp[start]==0)mp.erase(start);
            }
            else{ 
                mp[start-endTime[i-1]]--;
                 if(mp[start-endTime[i-1]]==0)mp.erase(start-endTime[i-1]);
            }
            if(i==n-1){
                mp[eventTime-end]--;
                if(mp[eventTime-end]==0)mp.erase(eventTime-end);
            }
            else {
                mp[startTime[i+1]-end]--;
                if(mp[startTime[i+1]-end]==0)mp.erase(startTime[i+1]-end);
            }
            if(!mp.empty()){
                int x=mp.rbegin()->first;
                if(x>=end-start){
                    if(i==0)ans=max(ans,startTime[i+1]);
                    else if(i==n-1)ans=max(ans,eventTime-endTime[i-1]);
                    else ans=max(ans,startTime[i+1]-endTime[i-1]);
                }
            }
            if(i==0){
                ans=max(ans,start+startTime[i+1]-end);
            }
            else if(i==n-1){
                ans=max(ans,start+eventTime-endTime[i-1]-end);
            }
            else ans=max(ans,startTime[i+1]+start-endTime[i-1]-end);
            if(i==0){
                mp[start]++;
            }
            else{ 
                mp[start-endTime[i-1]]++;
                
            }
            if(i==n-1){
                mp[eventTime-end]++;
                
            }
            else {
                mp[startTime[i+1]-end]++;
               
            }
        }
        return ans;
    }
};