class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
         vector<pair<int,char>> comb;
         string ans = "";
        
         for(int i=0;i<indices.size();i++){
             comb.push_back({indices[i],s[i]});
         }
        
         sort(comb.begin(),comb.end());
        
         for(int i=0;i<comb.size();i++){
             ans+= comb[i].second;
         }
		 return ans;
    }
};