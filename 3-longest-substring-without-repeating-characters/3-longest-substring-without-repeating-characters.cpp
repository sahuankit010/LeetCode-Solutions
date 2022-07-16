class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> chars(128);
        int ans = 0;
        int left=0,right=0;
        
        while(right<n){
            chars[s[right]]++;
            
            while(chars[s[right]]>1){
                chars[s[left]]--;
                left++;
            }
            
            ans=max(ans,right-left+1);
            right++;
        }

        return ans;
    }
};