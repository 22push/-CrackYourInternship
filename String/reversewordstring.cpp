class Solution {
public:
    string reverseWords(string s) {
        int n= s.length();
        vector<string>arr;
        string l="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(l.length()!=0){
                    cout<<l<< ' ';
                    arr.push_back(l);
                    l="";
                }
            }
            else{
                    l+=s[i];
                }
        }
        if(l.length()!=0){
                    cout<<l<< ' ';
                    arr.push_back(l);
                    l="";
                }
        string m="";
        for(int i=arr.size()-1;i>=0;i--){
            m+=arr[i];
            if(i!=0){
                m+=" ";
            }
        }
        return m;
    }
};