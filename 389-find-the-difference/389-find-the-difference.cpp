class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> hm1, hm2;
        
        for(char c: s){
            hm1[c]++;
        }
        
        for(char c: t){
            hm2[c]++;
        }
        for(auto x: hm2){
            if(x.second!= hm1[x.first]) return x.first;
        }
        return ' ';
    }
};