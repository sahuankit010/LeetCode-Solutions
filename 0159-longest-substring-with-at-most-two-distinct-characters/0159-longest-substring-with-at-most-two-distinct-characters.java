class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int n = s.length();
        if(n == 1 || n == 2) return n;
        
        Map<Character,Integer> umap = new HashMap<>();
                
        int ans = 0;
        
        char []ch = s.toCharArray();
        
        for(int i=0, j=0; i<n; i++){
            umap.put(ch[i], umap.getOrDefault(ch[i], 0) + 1);
            for(; j<i && umap.size() > 2; j++){
                if(umap.get(ch[j]) == 1){
                    umap.remove(ch[j]);
                } else{
                    umap.put(ch[j], umap.get(ch[j]) - 1);
                }
            }  
            ans = Math.max(ans, i-j+1);
        }
            
        
        return ans;
    }
}