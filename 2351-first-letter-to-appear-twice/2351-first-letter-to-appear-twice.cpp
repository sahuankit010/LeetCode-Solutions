class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char>h;
        
        for(char c: s){
            if(h.find(c)!=h.end()) return c;
            else h.insert(c);
        }
        return ' ';
    }
};