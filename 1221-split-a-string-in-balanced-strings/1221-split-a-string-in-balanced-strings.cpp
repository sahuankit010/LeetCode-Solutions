class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        unordered_map<char,int> ump;
        
        for(int i=0;i<s.length();i++){
            ump[s[i]]++;
            
            if(ump['L']==ump['R']){
                ans++;
                ump.clear();
            }
        }
        
        return ans;
    }
};