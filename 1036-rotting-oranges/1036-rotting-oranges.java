class Solution {
    int m;
    int n;
    public int orangesRotting(int[][] grid) {
        
        m = grid.length;
        n = grid[0].length;

        Queue<int[]> q = new ArrayDeque<>();

        int freshOrange = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) freshOrange++;
                else if(grid[i][j] == 2) q.offer(new int[] {i, j});
            }
        }

        if(freshOrange == 0) return 0;

        if(q.isEmpty()) return -1;

        int minutes = -1;

        while(!q.isEmpty()){
            int size = q.size();

            while(size-- > 0){
                int[] curr = q.poll();

                int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

                for(int k=0; k<4; k++){
                    int x = curr[0] + dirs[k][0];
                    int y = curr[1] + dirs[k][1];

                    if(isValid(x, y, grid)){
                        freshOrange--;
                        q.offer(new int[] {x, y});
                        grid[x][y] = 2;
                    }
                }
            }

            minutes++;
        }

        return freshOrange == 0? minutes : -1;
    }

    private boolean isValid(int row, int col, int[][] grid){

        return (row >= 0 && row < m && col >= 0 &&
        col < n && grid[row][col] == 1);
    }
}