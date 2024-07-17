class Solution {
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        boolean[][] vis = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word.charAt(0) && dfs(board, word, 0, i, j, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

    private boolean dfs(char[][] board, String word, int idx, int x, int y, boolean[][] vis) {
        if (idx == word.length()) {
            return true;
        }

        int m = board.length;
        int n = board[0].length;

        if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] || board[x][y] != word.charAt(idx)) {
            return false;
        }

        vis[x][y] = true;

        boolean found = dfs(board, word, idx + 1, x + 1, y, vis) ||
                        dfs(board, word, idx + 1, x - 1, y, vis) ||
                        dfs(board, word, idx + 1, x, y + 1, vis) ||
                        dfs(board, word, idx + 1, x, y - 1, vis);

        vis[x][y] = false;  // backtrack

        return found;
    }
}
