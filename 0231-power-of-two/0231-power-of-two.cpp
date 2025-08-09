class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0&&__builtin_popcount(n)==1)return true;
        return false;
    }
};