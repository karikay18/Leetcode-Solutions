class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        if(!matrix.size())return false;
        int m=matrix[0].size();
        int n=matrix.size();
        int end=(m*n)-1;
        int mid;
        while(start<=end)
        {   mid=start+(end-start)/2;
            if(matrix[mid/m][mid%m]==target)
            {
                return true;
            }
            else if(matrix[mid/m][mid%m]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return false;

        
    }
};