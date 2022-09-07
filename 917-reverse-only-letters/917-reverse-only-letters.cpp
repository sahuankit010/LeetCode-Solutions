class Solution {
public:
    string reverseOnlyLetters(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                temp += s[i];
            }
        }
        
        reverse(temp.begin(), temp.end());
        string ans="";
        int k = 0;
        
        for(int i=0;i<s.size(); i++){
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                ans += temp[k++];
            } else{
                ans += s[i];
            }
        }
        return ans;
    }
};