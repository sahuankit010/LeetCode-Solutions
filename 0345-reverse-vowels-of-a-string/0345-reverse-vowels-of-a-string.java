class Solution {
    public String reverseVowels(String s) {
        String ans = new String("");
        String temp = new String("");
        int n = s.length();
        for(int i=0; i<n; i++){
            char c = s.charAt(i);
            if(c=='a' || c=='e' || c=='i'|| c=='o' || c=='u' || c=='A' || c=='I' || c=='E' || c=='O' || c=='U') temp += c;
        }
        int n1 = temp.length()-1;
        
        for(int i=0; i<n; i++){
            char c = s.charAt(i);
            if(c=='a' || c=='e' || c=='i'|| c=='o' || c=='u' || c=='A' || c=='I' || c=='E' || c=='O' || c=='U'){
                ans += temp.charAt(n1--); 
            } else{
                ans += c;
            }
        }
        return ans;
    }
}