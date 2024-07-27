class Solution {
public:
    bool cheack(string s ,int l,int r,int k){
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else if(k==0){
                return cheack(s,l+1,r,k+1) || cheack(s,l,r-1,k+1);
            }
            else {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        return cheack(s,0,s.length()-1,0);
    }
};