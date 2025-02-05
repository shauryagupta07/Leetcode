class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
      if(s1==s2)return true;
      int cnt=0;
      int id1=-1,id2=-1;
      for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
          if(id1==-1)id1=i;
          else if(id2==-1)id2=i;
          cnt++;
        }
      }
      if(cnt!=2){
        return false;
      }
      if(s2[id1]==s1[id2]&&s2[id2]==s1[id1])return true;
      else return false;
    }
};