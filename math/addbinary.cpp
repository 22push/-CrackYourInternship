class Solution {
public:
    string addBinary(string a, string b) {
        string s="";
        char x;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a[0]=='1' && b[0]=='1'){
            x='1';
            s+='0';
        }
        else if(a[0]=='0' && b[0]=='0'){
            x='0';
            s+='0';
        }
        else {
            x='0';
            s+='1';
        }
        int i;
        for( i=1;i<min(a.length(),b.length());i++){
            if(a[i]=='1' && b[i]=='1' && x=='1'){
                s+='1';
                x='1';
            }
            else if(a[i]=='1' && b[i]=='1' && x=='0'){
                s+='0';
                x='1';
            }
            else if(a[i]=='0' && b[i]=='0' && x=='1'){
                s+='1';
                x='0';
            }
            else if(a[i]=='0' && b[i]=='0' && x=='0'){
                s+='0';
                x='0';
            }
            else if(x=='1'){
                s+='0';
                x='1';
            }
            else{
                s+='1';
                x='0';
            }
        }
        if(a.length()>b.length()){
            for(int j=i;j<a.length();j++){
                if(a[j]=='1' && x=='1'){
                    s+='0';
                    x='1';
                }
                else if(a[j]=='0' && x=='0'){
                    s+='0';
                    x='0';
                }
                else{
                    s+='1';
                    x='0';
                }
            }
        }
        else{
             for(int j=i;j<b.length();j++){
                if(b[j]=='1' && x=='1'){
                    s+='0';
                    x='1';
                }
                else if(b[j]=='0' && x=='0'){
                    s+='0';
                    x='0';
                }
                else{
                    s+='1';
                    x='0';
                }
            }
        }
        if(x=='1'){
            s+='1';
        }
        reverse(s.begin(), s.end());
        return s;
    }
};