class Solution {
    Map<Integer, Integer> map = new HashMap<>();

    public Solution(){
        map.put(0, 1);
        map.put(1, 1);
    }

    public int numTrees(int n) {
        if(map.containsKey(n)) return map.get(n);
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += numTrees(i) * numTrees(n - i - 1);
        }
        map.put(n, result);

        return result;
    }
}