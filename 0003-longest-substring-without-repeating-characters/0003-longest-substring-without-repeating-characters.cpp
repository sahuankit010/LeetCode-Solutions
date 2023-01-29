class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> ump;
        
        int left = 0, right = 0;
        int ans = 0;
        while(right < n){
            
            char r = s[right];
            ump[r]++;
            
            while(ump[r]>1){
                char l = s[left];
                ump[l]--;
                left++;
            }
            
            ans = max(ans, right - left + 1);
            right++;
        }
        
        return ans;
    }
};