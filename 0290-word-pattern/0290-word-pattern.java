class Solution {
    public boolean wordPattern(String pattern, String s) {
        
        Map<Character, String> charToWord = new HashMap<>();
        Map<String, Character> wordToChar = new HashMap<>();

        String[] st = s.split(" ");

        if(st.length != pattern.length()) return false;

        for(int j = 0, i = 0; j<pattern.length(); j++, i++){
            char ch = pattern.charAt(j);

            if(!charToWord.containsKey(ch)){
                charToWord.put(ch, st[i]);
            } 
            if (!wordToChar.containsKey(st[i])) {
                wordToChar.put(st[i], ch);
            }

            if(!charToWord.get(ch).equals(st[i]) || !wordToChar.get(st[i]).equals(ch))
                return false;

        }

        for(Map.Entry<Character, String> set:  charToWord.entrySet()){
            System.out.println(set.getKey() + " " + set.getValue());
        }

        return true;
    }
}