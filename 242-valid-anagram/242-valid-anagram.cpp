class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>ump;
        for(int i=0;i<s.length();i++){
            ump[s[i]]++;
        }
        
        for(int i=0;i<t.length();i++){
            ump[t[i]]--;
        }
        if(ump.empty()) return true;
        for(auto it: ump){
            if(it.second!=0) return false;
        }
        
        return true;
    }
};