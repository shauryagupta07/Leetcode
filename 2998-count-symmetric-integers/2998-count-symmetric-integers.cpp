class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            int x=i;
            vector<int>dig;
            while(x){
                dig.push_back(x%10);
                x/=10;
            }
            if(dig.size()%2==1)continue;
            int sum1=0,sum2=0;
            for(int j=0;j<dig.size()/2;j++){
                sum1+=dig[j];
            }
            for(int j=dig.size()/2;j<dig.size();j++)sum2+=dig[j];
            if(sum1==sum2)cnt++;
        }
        return cnt;
    }
};