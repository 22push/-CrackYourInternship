class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        int dp[n];
        dp[0]=1;
        int last=0;
        if(s[0]==48){
            return 0;
        }
        for(int i=1;i<n;i++){
            if((s[i-1]==49 && s[i]>48) || (s[i-1]==50 && s[i]>48 && s[i]<55)){
                if(i>1){
                    dp[i]=dp[i-1]+dp[i-2];
                }
                else{
                    dp[i]=dp[i-1]+1;
                }
                last++;
            }
            else if(s[i]==48 && (s[i-1]>50 || s[i-1]==48)){
                return 0;
            }
            else{
                if(s[i]==48 && last!=0){
                    // cout<<"dsfbg";
                    if(i>1){
                        dp[i]=dp[i-2];
                    }
                    else{
                        dp[i]=1;
                    }
                }
                else{
                    dp[i]=dp[i-1];
                }
            }
        }
        return dp[n-1];
    }
};