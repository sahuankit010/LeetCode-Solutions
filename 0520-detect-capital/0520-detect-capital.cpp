class Solution {
public:
    bool detectCapitalUse(string word) {
        bool upperCase = false, lowerCase = false;
        int n = word.length();
        if(n==1) return true;
        for(int i=1; i<n; i++){
            if(isupper(word[i])) upperCase = true;
            else lowerCase = true;
        }
        bool first = isupper(word[0]);
        
        return ((!lowerCase && upperCase && first) || (!upperCase && lowerCase && !first) || (first && !upperCase && lowerCase));
    }
};