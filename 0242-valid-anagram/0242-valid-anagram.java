class Solution {
    public boolean isAnagram(String s, String t) {
        int [] arr = new int[26];
        
        for(int i=0; i<26; i++){
            System.out.print(arr[i] + " ");
        }
        char[] sarr = s.toCharArray();
        char[] tarr = t.toCharArray();
        for(char c: sarr){
            arr[c-97]++;
        }
        
        for(char c: tarr){
            arr[c-97]--;
        }
        
        for(int i=0; i<26; i++){
            if(arr[i]!=0) return false;
        }
        return true;
    }
}