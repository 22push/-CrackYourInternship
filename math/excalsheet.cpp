class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str="";
        
        while(columnNumber > 0){
            char ch = char(ceil((columnNumber-1)%26 + 65));
            cout<<ch<<endl;
            str = ch+str;
            columnNumber = (columnNumber-1)/26;
        }
        return str;
    }
};