class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int> ump1,ump2;
        int n=word1.size();
        for(int i=0; i<n; i++){
            ump1[word1[i]]++;
            ump2[word2[i]]++;
        }

        for(auto x: ump1){
            if(abs(ump1[x.first]-ump2[x.first])>3) return false;
        }
        
        for(auto x: ump2){
            if(abs(ump1[x.first]-ump2[x.first])>3) return false;
        }
        return true;
    }
};