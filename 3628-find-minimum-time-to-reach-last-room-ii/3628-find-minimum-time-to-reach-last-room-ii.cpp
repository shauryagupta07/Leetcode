class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size(),m=moveTime[0].size();
        vector<vector<vector<int>>>dist(n,vector<vector<int>>(m,vector<int>(2,INT_MAX)));
        int delr[4]={1,-1,0,0};
        int delc[4]={0,0,1,-1};
        set<pair<pair<int,int>,pair<int,int>>>s;
        s.insert({{0,0},{0,0}});
        dist[0][0][0]=0;
        while(!s.empty()){
            auto it=*s.begin();
            int time=it.first.first;
            int turn=it.first.second;
            int r=it.second.first,c=it.second.second;
            s.erase(it);
            for(int i=0;i<4;i++){
                int row=r+delr[i];
                int col=c+delc[i];
                if(row<0||row>=n||col<0||col>=m)continue;
                int t=max(moveTime[row][col],time);
                if(dist[row][col][turn]>t+turn+1){
                    if(s.find({{dist[row][col][turn],1-turn},{row,col}})!=s.end())s.erase({{dist[row][col][turn],1-turn},{row,col}});
                    dist[row][col][turn]=t+turn+1;
                    s.insert({{dist[row][col][turn],1-turn},{row,col}});
                }
            }
        }
        return min(dist[n-1][m-1][0],dist[n-1][m-1][1]);
    }
};