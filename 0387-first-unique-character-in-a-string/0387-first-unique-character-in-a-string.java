class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> hash = new HashMap<>();
        
        for(char c: s.toCharArray()){
           hash.put(c, hash.getOrDefault(c, 0) + 1);
  
        }
        
        for(int i=0; i<s.length(); i++){
            if(hash.get(s.charAt(i)) == 1) return i;
        }
        
        return -1;
    }
}