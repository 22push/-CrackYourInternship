class Solution {
public:
    void getall(int tot,vector<string>&ans,string s,int st,int co){
        if(tot==s.size()){
            ans.push_back(s);
            return ;
        }
        if(st>co){
            getall(tot,ans,s+")",st,co+1);
            if(st<tot/2){
                getall(tot,ans,s+"(",st+1,co);
            }
        }
        else{
            getall(tot,ans,s+"(",st+1,co);
        }
    }
    vector<string> generateParenthesis(int n) {
        int to=2*n;
        vector<string>ans;
        getall(to,ans,"",0,0);
        return ans;
    }
};