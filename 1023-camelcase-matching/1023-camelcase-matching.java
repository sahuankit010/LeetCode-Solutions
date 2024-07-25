class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {

        List<Boolean> ans = new ArrayList<>();

        for (String curr : queries) {
            ans.add(func(curr, pattern));
        }

        return ans;
    }

    private boolean func(String query, String pattern) {

        int m = query.length(); // i
        int n = pattern.length(); // j

        int i = 0; // Pointer for query
        int j = 0;  // Pointer for pattern

        while (i < m && j < n) { // i is for queries and j is for pattern
            if (query.charAt(i) == pattern.charAt(j)) {
                i++;
                j++;
            } else if (Character.isUpperCase(query.charAt(i))) {
                return false;
            } else {
                i++;
            }
        }

        while (i < m) {
            if (Character.isUpperCase(query.charAt(i)))
                return false;
            i++;
        }
        return (j == n);
    }
}