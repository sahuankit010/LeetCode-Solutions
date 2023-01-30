class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int row, int col){
        if(row<0 || row == board.size() || col < 0 || 
           col == board[0].size() or board[row][col] != 'O') return;
        
        board[row][col] = 'T';
        
        dfs(board, row+1, col);
        dfs(board, row-1, col);
        dfs(board, row, col+1);
        dfs(board, row, col-1);
    }
    void solve(vector<vector<char>>& board) {
        int rowL = board.size();
        int colL = board[0].size();
        
        for(int i=0; i<rowL; i++){
            for(int j=0; j<colL; j++){
                if((i==0 || i==rowL-1 || j==0 || j==colL-1) && board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }
        
        for(int i=0; i<rowL; i++){
            for(int j=0; j<colL; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        for(int i=0; i<rowL; i++){
            for(int j=0; j<colL; j++){
                if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};