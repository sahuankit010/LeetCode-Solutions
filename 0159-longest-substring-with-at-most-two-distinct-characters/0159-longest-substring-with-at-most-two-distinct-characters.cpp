class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n= s.length();
        if(n == 1 || n == 2) return n;
        
        unordered_map<char, int> umap;
        
        umap[s[0]]++;
        umap[s[1]]++;
        
        int ans = 0;
        
        for(int i=2, j=0; i<n; i++){
            umap[s[i]]++;
            for(; j<i && umap.size() > 2; j++){
                if(umap[s[j]] == 1){
                    umap.erase(s[j]);
                } else{
                    umap[s[j]]--;
                }
            }  
            ans = max(ans, i-j+1);
        }
            
        
        return ans;
    }
};