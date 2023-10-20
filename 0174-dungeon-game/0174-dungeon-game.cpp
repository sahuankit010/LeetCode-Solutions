class Solution {
public:
    int f(int i, int j, int m, int n, vector<vector<int>>& d, vector<vector<int>>& memo){
        if(i>=m || j>=n) return INT_MAX;

        if(i==m-1 && j==n-1){
            return d[i][j]>0? 1 : 1- d[i][j];
        }

        if(memo[i][j]!=-1) return memo[i][j];

        int down  = f(i+1, j, m, n, d, memo);
        int right = f(i, j+1, m, n, d, memo);

        int health = min(down, right) - d[i][j];

        return memo[i][j] = health>0?health:1;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> memo(m+1, vector<int> (n+1, -1));
        return f(0,0, m, n, dungeon, memo);
    }
};