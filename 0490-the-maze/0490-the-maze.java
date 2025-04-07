class Solution {
    int m;
    int n;
    boolean[][] visited;

    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        m = maze.length;
        n = maze[0].length;
        visited = new boolean[m][n];
        return dfs(maze, start[0], start[1], destination[0], destination[1]);
    }

    private boolean dfs(int[][] maze, int r, int c, int fr, int fc){
        if(r == fr && c == fc) return true;

        if(visited[r][c]) return false;

        visited[r][c] = true;

        int[][] dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        for(int i=0; i<4; i++){
            int newX = r;
            int newY = c;
            while(isValid(maze, newX+dirs[i][0], newY+dirs[i][1])){
                newX += dirs[i][0];
                newY += dirs[i][1];
            }

            if(dfs(maze, newX, newY, fr, fc)) return true;
        }

        return false;
    }

    private boolean isValid(int[][] maze, int r, int c){
        return (
            r >= 0 && r<m &&
            c >=0 && c<n &&
            maze[r][c] == 0
        );
    }
}