class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int idx = -1;
        int n=word.size();
        
        for(int i=0; i<n; i++){
            if(word[i]==ch){
                idx=i;
                break;
            }
        }
        if(idx>=n) return word;
        string res = word.substr(0,idx+1);
        reverse(res.begin(), res.end());
        
        for(int i= idx+1; i<n; i++){
            res += word[i];
        }
        return res;
    }
};