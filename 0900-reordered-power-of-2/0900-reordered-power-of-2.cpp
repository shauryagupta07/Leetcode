class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        int i=1;
        vector<string>v;
        while(i<1000000000){
            string temp=to_string(i);
            sort(temp.begin(),temp.end());
            v.push_back(temp);
            i*=2;
        }
        sort(s.begin(),s.end());
        for(int i=0;i<v.size();i++){
            if(s==v[i])return true;
        }
        return false;
    }
};