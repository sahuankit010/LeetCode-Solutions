class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        int countAbs = 0;
        for(int i=0; i<n;i++){
            if(s[i]=='A'){
                countAbs++;
            }
            if(countAbs>1) return false;
        }
        
        for(int i=2; i<n; i++){
            if(s[i-2]=='L' && s[i-1]=='L' && s[i]=='L') return false;
        }
        
        return true;
    }
};