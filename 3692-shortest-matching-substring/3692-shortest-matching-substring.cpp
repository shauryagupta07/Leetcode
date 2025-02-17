class Solution {
public:
    #define ll long long
    const ll p = 31, mod = 1e9 + 7;

ll poly_hash(string s) {
	ll hash = 0;
	ll p_power = 1;

	for (int i = 0; i < s.size(); i++) {
		hash += (s[i] - 'a' + 1) * p_power;
		p_power *= p;

		hash %= mod;
		p_power %= mod;
	}

	return hash;
}
    ll powr(ll a, ll b) {
	// (a^b)%mod
	int res = 1;
	while (b) {
		if (b & 1) res = (res*a)%mod;
		b /= 2;
		a=(a*a)%mod;

		a %= mod;
		res %= mod;
	}
	return res;
}
ll inv(ll x) {
	return powr(x, mod - 2);
}
    
    int shortestMatchingSubstring(string s, string t) {
        vector<int>v1,v2,v3;
        int id1=-1,id2;
        for(int i=0;i<t.length();i++){
            if(t[i]=='*'){
                if(id1==-1)id1=i;
                else id2=i;
            }
        }
        string first=t.substr(0,id1);
        
        string mid=t.substr(id1+1,id2-id1-1);
        
        string last=t.substr(id2+1,t.length()-id2-1);
        
        ll h1=poly_hash(first),h2=poly_hash(mid),h3=poly_hash(last);
        
        int n=s.length(),m=first.length();
        
        ll text_hash = poly_hash(s.substr(0, m));
        if (text_hash == h1) {
			v1.push_back(0);
		}
        
        for (int i = 1; i + m <= n; i++) {
            
		text_hash = (text_hash - (s[i - 1] - 'a' + 1) + mod) % mod;

		text_hash = (text_hash * inv(p)) % mod;

		text_hash = (text_hash + (s[i + m - 1] - 'a' + 1) * powr(p, m - 1)) % mod;

		if (text_hash == h1) {
			v1.push_back(i);
		}
	}
        m=mid.length();
        text_hash = poly_hash(s.substr(0, m));
        if (text_hash == h2) {
			v2.push_back(0);
		}
        for (int i = 1; i + m <= n; i++) {
            
		text_hash = (text_hash - (s[i - 1] - 'a' + 1) + mod) % mod;

		text_hash = (text_hash * inv(p)) % mod;

		text_hash = (text_hash + (s[i + m - 1] - 'a' + 1) * powr(p, m - 1)) % mod;

		if (text_hash == h2) {
			v2.push_back(i);
		}
	}
        m=last.length();
        text_hash = poly_hash(s.substr(0, m));
        if (text_hash == h3) {
			v3.push_back(0);
		}
        for (int i = 1; i + m <= n; i++) {
		
		text_hash = (text_hash - (s[i - 1] - 'a' + 1) + mod) % mod;

		text_hash = (text_hash * inv(p)) % mod;

		text_hash = (text_hash + (s[i + m - 1] - 'a' + 1) * powr(p, m - 1)) % mod;

		if (text_hash == h3) {
			v3.push_back(i);
		}
	}

        //case-1:---*---*
        int ans=INT_MAX;
        if(last.length()==0&&first.length()>0&&mid.length()>0){
            for(int i=0;i<v1.size();i++){
                int x=first.length(),y=mid.length();
                int idx=v1[i];
                int lb=lower_bound(v2.begin(),v2.end(),idx+x)-v2.begin();
                if(lb<v2.size()){
                    ans=min(ans,v2[lb]+y-idx);
                }
            }
            if(ans==INT_MAX)return -1;
            return  ans;
        }
        //case 2 *---*---
        if(first.length()==0&&last.length()>0&&mid.length()>0){
            for(int i=0;i<v2.size();i++){
                int x=mid.length(),y=last.length();
                int idx=v2[i];
                int lb=lower_bound(v3.begin(),v3.end(),idx+x)-v3.begin();
                if(lb<v3.size()){
                    ans=min(ans,v3[lb]+y-idx);
                }
            }
            if(ans==INT_MAX)return -1;
            return  ans;
        }
        //case-3:---*---*---
         if(first.length()>0&&last.length()>0&&mid.length()>0){
            for(int i=0;i<v1.size();i++){
                int x=first.length(),y=mid.length(),z=last.length();
                int idx=v1[i];
                int lb=lower_bound(v2.begin(),v2.end(),idx+x)-v2.begin();
                if(lb<v2.size()){
                    int k=v2[lb];
                    int lb2=lower_bound(v3.begin(),v3.end(),k+y)-v3.begin();
                    if(lb2<v3.size()){
                    ans=min(ans,v3[lb2]+z-idx);
                    }
                }
            }
             if(ans==INT_MAX)return -1;
            return  ans;
        }
        //case-4:**---
        if(first.length()==0&&mid.length()==0&&last.length()>0){
            int x=last.length();
            if(v3.size()>0)return x;
        }
        //case-5:---**
        if(first.length()>0&&mid.length()==0&&last.length()==0){
            int x=first.length();
            if(v1.size()>0)return x;
        }
        if(first.length()==0&&mid.length()==0&&last.length()==0){
            return 0;
        }
        if(first.length()==0&&mid.length()>0&&last.length()==0){
            int x=mid.length();
            if(v2.size()>0)return x;
        }
        if(last.length()>0&&first.length()>0&&mid.length()==0){
            for(int i=0;i<v1.size();i++){
                int x=first.length(),y=last.length();
                int idx=v1[i];
                int lb=lower_bound(v3.begin(),v3.end(),idx+x)-v3.begin();
                if(lb<v3.size()){
                    ans=min(ans,v3[lb]+y-idx);
                }
            }
            if(ans==INT_MAX)return -1;
            return  ans;
        }
        return -1;
    }
};