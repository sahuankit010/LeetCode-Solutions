class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hm;
        
        for(int i=0;i<magazine.length();i++){
            hm[magazine[i]]++;
        }
        
        for(int i=0;i<ransomNote.length();i++) {
            if(hm[ransomNote[i]]>0) hm[ransomNote[i]]--;
            else return false;
        }
        // for(auto x: hm){
        //     if(x.second>1) return false;
        // }
        return true;
    }
};