class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ump;
        
        for(char c: s){
            ump[c]++;
        }
        
        for(char c: t){
            ump[c]--;
        }
        
        for(auto it: ump){
            if(it.second) return false;
        }
        
        return true;
    }
};