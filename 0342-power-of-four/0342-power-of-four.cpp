class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0||__builtin_popcount(n)!=1)return false;
        if(n%3==1)return true;
        return false;
    }
};