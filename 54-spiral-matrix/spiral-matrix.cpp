class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        int sr = 0, er = m - 1;
        int sc = 0, ec = n - 1;
        vector<int> res;
        
        while (sr <= er && sc <= ec) {
            // Traverse from left to right
            for (int i = sc; i <= ec; i++) {
                res.push_back(matrix[sr][i]);
            }
            sr++;
            
            // Traverse downwards
            for (int i = sr; i <= er; i++) {
                res.push_back(matrix[i][ec]);
            }
            ec--;
            
            // Traverse from right to left
            if (sr <= er) {
                for (int i = ec; i >= sc; i--) {
                    res.push_back(matrix[er][i]);
                }
                er--;
            }
            
            // Traverse upwards
            if (sc <= ec) {
                for (int i = er; i >= sr; i--) {
                    res.push_back(matrix[i][sc]);
                }
                sc++;
            }
        }
        
        return res;
    }
};
