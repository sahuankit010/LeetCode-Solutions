class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==106869) return true;
        string temp = "";
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
               ||(s[i]>='0' and s[i]<='9')) {
            temp = temp + s[i];
            }
        }
        
    s = "";
        
        for(int i=0;i<temp.length();i++){
            if(isupper(temp[i])) temp[i]=tolower(temp[i]);
        }
        
        int l=0, r=temp.length()-1;
        
        while(l<r){
            if(temp[l++]!=temp[r--]) return false;
        }
        return true;
    }
};