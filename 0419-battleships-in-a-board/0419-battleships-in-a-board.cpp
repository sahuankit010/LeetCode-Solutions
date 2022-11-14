class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty() || board.front().empty()) return 0;
    
        int rowCount = board.size();
        int colCount = board.front().size();
    
        int count{0};
        for(int i = 0; i < rowCount; ++i) {
            for(int j = 0; j < colCount; ++j) {
                if(board[i][j] == 'X') {
                    if(i > 0 && board[i - 1][j] == 'X') continue;
                    if(j > 0 && board[i][j - 1] == 'X') continue;
                    ++count;
                }
            }
        }
        return count;
    }
};