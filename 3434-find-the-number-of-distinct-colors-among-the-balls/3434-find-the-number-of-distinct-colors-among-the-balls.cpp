class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
      map<int,int>mp,color;
      vector<int>res;
      for(int i=0;i<queries.size();i++){
        int ball=queries[i][0];
        int col=queries[i][1];
        if(color.find(ball)!=color.end()){
          int prev=color[ball];
          mp[prev]--;
          if(mp[prev]==0)mp.erase(prev);
        }
        mp[col]++;
        color[ball]=col;
        res.push_back(mp.size());
      }
      return res;
    }
};