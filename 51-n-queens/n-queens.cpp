class Solution {
public:
    bool safe(int row,int col,vector<string>board,int n)
    {
        int drow=row;
        int dcol=col;
         while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }
      col=dcol;
      row=drow;
       while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }
      col=dcol;
      row=drow;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;


    }
    void solve(int col,vector<string> &board,vector<vector<string>> &res,int n)
    {
        if(col==n)
        {
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(safe(i,col,board,n))
            {
                board[i][col]='Q';
                solve(col+1,board,res,n);
                board[i][col]='.';

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,res,n);
        return res;
    }
};