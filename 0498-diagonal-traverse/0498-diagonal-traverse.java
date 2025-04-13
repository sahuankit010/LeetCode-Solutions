class Solution {
    int m;
    int n;

    public int[] findDiagonalOrder(int[][] mat) {
        m = mat.length;
        n = mat[0].length;
        int[] ans = new int[m * n];

        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = i + j;

                map.computeIfAbsent(sum, k -> new ArrayList()).add(mat[i][j]);
            }
        }
        int idx = 0;
        for (int key : map.keySet()) {
            List<Integer> list = map.get(key);
            if (key % 2 == 0) {
                Collections.reverse(list);
            }
            for (int i : list) {
                ans[idx++] = i;

            }
        }
        return ans;
    }
}