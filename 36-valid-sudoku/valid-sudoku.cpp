class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            unordered_set<char> row;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (row.find(board[i][j]) == row.end())
                    row.insert(board[i][j]);
                else
                    return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            unordered_set<char> col;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.')
                    continue;
                if (col.find(board[j][i]) == col.end())
                    col.insert(board[j][i]);
                else
                    return false;
            }
        }
        for (int box = 0; box < 9; box++) {
            unordered_set<char> subBox;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = 3 * (box / 3) + i;
                    int col = 3 * (box % 3) + j;
                    if (board[row][col] == '.')
                        continue;
                    if (subBox.find(board[row][col]) == subBox.end())
                        subBox.insert(board[row][col]);
                    else
                        return false;
                }
            }
        }

        return true;
    }
};