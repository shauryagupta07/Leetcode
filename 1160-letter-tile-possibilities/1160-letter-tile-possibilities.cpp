class Solution {
public:
void f(int i,string &s,vector<int>&vis,set<string>&st,string &tiles){
    if(i==tiles.length()){
        if(st.find(s)==st.end())st.insert(s);
        return;
    }
    f(i+1,s,vis,st,tiles);
    for(int j=0;j<tiles.length();j++){
        if(!vis[j]){
            s.push_back(tiles[j]);
            vis[j]=1;
            f(i+1,s,vis,st,tiles);
            vis[j]=0;
            s.pop_back();
        }
    }
}
    int numTilePossibilities(string tiles) {
        int n=tiles.length();
        vector<int>vis(n,0);
        string s="";
        set<string>st;
        f(0,s,vis,st,tiles);
        return st.size()-1;
    }
};