class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> hash = new HashMap<>();
        
        for(int i=0; i<s.length(); i++){
            if(hash.get(s.charAt(i)) == null)
                hash.put(s.charAt(i), 1);
            else
                hash.put(s.charAt(i), hash.get(s.charAt(i)) + 1);
                
            // hash.getOrDefault(1, hash.get(s.charAt(i)) + 1);
        }
        
        for(int i=0; i<s.length(); i++){
            if(hash.get(s.charAt(i)) == 1) return i;
        }
        
        return -1;
    }
}