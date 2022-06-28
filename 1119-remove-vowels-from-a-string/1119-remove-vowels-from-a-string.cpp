class Solution {
public:
    string removeVowels(string s) {
        string ans="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]!='a' and s[i]!='e' and s[i]!='i' and s[i]!='o' and s[i]!='u'){
                ans+=s[i];
            }
        }
        return ans;
    }
};