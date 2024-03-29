class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int row=m-1;
        int col=0;
        while(row>=0 && col<n)
        {
            if(target==matrix[row][col])
            {
                return true;
            }
            else if(target<matrix[row][col])
            {
                row--;
            }
            else
            {
                col++;
            }
        }
        return false;
    }
};