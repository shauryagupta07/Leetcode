class Solution {
public:
bool f(int i,int sum,string &s){
  if(i==s.length()){
    if(sum==0)return true;
    return false;
  }
  bool ans=false;
  string str="";
  for(int j=i;j<s.length();j++){
    str.push_back(s[j]);
    int su=stoi(str);
    ans=ans|f(j+1,sum-su,s);
  }
  return ans;
}
    int punishmentNumber(int n) {
      int ans=0;
      for(int i=1;i<=n;i++){
        int x=(i*i);
        string s=to_string(x);
        if(f(0,i,s)){
          ans+=x;
          cout<<i<<endl;
        }
      }
      return ans;
    }
};