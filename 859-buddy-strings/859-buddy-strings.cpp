class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int hash[26] = {0} ;         
        int hashb[26] = {0} ; 
        int ct = 0 ;
        for(int i = 0 ; i < s.size() ;i++){
            hash[s[i] - 'a']++;
            hashb[goal[i] - 'a']++;
            if(s[i]!=goal[i]) ct++;
        }
        
        for(int i = 0 ; i < 26 ; i++) if (hash[i]!=hashb[i]) return false;
        for(int i = 0 ; i < 26 ; i++) 
            if (hash[i] >=2 ){
                if(ct == 0 || ct == 2)
                    return true;
            }
        return ct == 2;
    }
};