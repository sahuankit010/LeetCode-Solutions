class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        string rev  = "";
        int revLen = 0;
        for(int i=0; i<n; i++){
            
            //even palindrome string case:
            
            int l = i, r = i;
            
            while(l >= 0 && r < n && s[l] == s[r]){
                if(revLen< r-l+1){
                    revLen = r-l+1;
                    rev = s.substr(l, revLen);
                }
                l--; 
                r++;
            }
            
            //odd case
            
            l = i;
            r = i+1;
            
            while(l >= 0 && r < n && s[l] == s[r]){
                if(revLen< r-l+1){
                    revLen = r-l+1;
                    rev = s.substr(l, revLen);
                }
                l--; 
                r++;
            }
        }
        
        return rev;
    }
};