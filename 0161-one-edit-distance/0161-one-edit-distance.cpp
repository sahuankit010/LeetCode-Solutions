class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sLen = s.size(), tLen = t.size();
        // sort(begin(s), end(s));
        // sort(begin(t), end(t));
        
        int i=0, j=0, count = 0;
        
        while(i<sLen && j<tLen){
            if(s[i] != t[j]){
                count++;
                if(sLen>tLen) i++;
                else if(sLen< tLen)j++;
                else{
                    i++; j++;
                }
            } else{
                i++;
                j++;
            }
            
        }
        
        while(i<sLen) {
            i++;
            count++;
        }
        
        while(j<tLen) {
            j++;
            count++;
        }
        
        return count == 1;
    }
};