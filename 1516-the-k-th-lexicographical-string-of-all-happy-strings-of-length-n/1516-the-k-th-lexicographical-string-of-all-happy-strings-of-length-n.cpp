class Solution {
public:
void f(int i,char prev,int n,string &s,set<string>&st){
    if(i==n){
        st.insert(s);
        return;
    }
    for(char ch='a';ch<='c';ch++){
        if(ch==prev)continue;
        s.push_back(ch);
        f(i+1,ch,n,s,st);
        s.pop_back();
    }
}
    string getHappyString(int n, int k) {
        string s="";
        set<string>st;
        char prev='d';
        f(0,prev,n,s,st);
        for(auto it:st){
            k--;
            if(k==0)return it;
        }
        return "";
    }
};