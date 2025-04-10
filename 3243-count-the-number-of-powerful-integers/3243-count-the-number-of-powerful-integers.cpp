class Solution {
public:
    long long find(string x, string s, int limit){
        int n = x.size(), m = s.size();
        if(n < m) return 0;
        if(n==m) return x>=s ? 1: 0;

        string suff = x.substr(n-m, m);
        long long ans = 0;
        int prev = n-m;

        for(int i=0; i<prev; i++){
            if(limit < (x[i]-'0')){
                ans += (long)pow(limit+1, prev-i);
                return ans;
            }
            ans += (long)(x[i]-'0')*(long)pow(limit+1, prev-i-1);
        }

        if(suff >= s) ans++;
        return ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string st = to_string(start-1);
        string fn = to_string(finish);

        return find(fn, s, limit)-find(st, s, limit);
    }
};