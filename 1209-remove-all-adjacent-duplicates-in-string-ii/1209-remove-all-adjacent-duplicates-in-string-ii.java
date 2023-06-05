class Solution {
    static class Pair {
        char first;
        int second;
        
        Pair(char first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    public String removeDuplicates(String s, int k) {
        ArrayDeque<Pair> st = new ArrayDeque<>();
        
        st.push(new Pair(s.charAt(0), 1));
        
        for (int i = 1; i < s.length(); i++) {
            if (!st.isEmpty()) {
                if (st.peek().first == s.charAt(i)) {
                    Pair topPair = st.peek();
                    st.push(new Pair(s.charAt(i), topPair.second + 1));
                } else {
                    st.push(new Pair(s.charAt(i), 1));
                }
            } else {
                st.push(new Pair(s.charAt(i), 1));
            }
            
            if (st.peek().second == k) {
                int count = 0;
                
                while (!st.isEmpty() && count < k) {
                    st.pop();
                    count++;
                }
            }
        }
        
        StringBuilder ans = new StringBuilder();
        
        while (!st.isEmpty()) {
            ans.append(st.peek().first);
            st.pop();
        }
        
        return ans.reverse().toString();
    }
}