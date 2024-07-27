class Solution {
public:
    bool cheack(string s,string s1,int i,int m){
        for(int j=i;j<i+m;j++){
            if(s[j]!=s1[j-i]){
                return false;
            }
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m= needle.length();
        for(int i=0;i<=n-m;i++){
            if(cheack(haystack,needle,i,m)){
                return i;
            }
        }
        return -1;
    }
};