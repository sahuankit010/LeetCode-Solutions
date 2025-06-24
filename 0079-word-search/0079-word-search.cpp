class Solution {
public:
    int m,n;
    int size;
    bool dfs(vector<vector<char>>& board, int i, int j, string &word, int currIdx = 0){
        if(currIdx == size) return true;
        if(i<0 || i==m || j<0 || j==n) return false;

        if(word[currIdx] != board[i][j]) return false;
        
        char ch = board[i][j];

        board[i][j] = '$';

        bool left = dfs(board, i, j-1, word, currIdx+1);

        bool right = dfs(board, i, j+1, word, currIdx+1);

        bool top = dfs(board, i-1, j, word, currIdx+1);

        bool bottom = dfs(board, i+1, j, word, currIdx+1);

        board[i][j] = ch;

        return (left || right || top || bottom);

    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        size = word.size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, i, j, word)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};