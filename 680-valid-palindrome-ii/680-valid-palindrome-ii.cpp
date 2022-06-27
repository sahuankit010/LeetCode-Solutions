class Solution {
public:
    bool helper(string s,int i, int j){
        int left = i, right = j;
        
        while(left<=right){
            
           if(s[left]!=s[right]){
               return false; 
           }
            left++;
            right--;
        }
        
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.length()-1;
       
        while(left<=right){
            
           if(s[left]!=s[right]){
               return helper(s,left+1,right) or helper(s,left,right-1);
           }
            left++;
            right--;
        }
        
        return true;
    }
};