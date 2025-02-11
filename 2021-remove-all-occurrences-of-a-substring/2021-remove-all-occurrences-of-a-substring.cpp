class Solution {
public:
    string removeOccurrences(string s, string part) {
       string temp="";
        int n=s.length(),m=part.length();
        
        for(int i=0;i<n;i++){
         temp.push_back(s[i]);
         int l=temp.length();
         if(l<m)continue;
         string sub=temp.substr(l-m,m);
         if(sub==part){
          int cnt=0;
          while(cnt<m){
            temp.pop_back();
            cnt++;
          }
         }
        }
        return temp;
    }
};