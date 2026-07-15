class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int s = 0, e = n-1;

        while(s <= e) {
            int m = s + (e-s)/2;
            if(target == matrix[row][m]) {
                return true;
            }
            else if(target < matrix[row][m]) {
                e = m-1;
            }
            else {
                s = m+1;
            }
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int sRow = 0, eRow = m-1;

        while(sRow <= eRow) {
            int midRow = sRow + (eRow - sRow) / 2;
            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]) {
                return searchInRow(matrix, target, midRow);
            }
            else if(target < matrix[midRow][0]) {
                eRow = midRow - 1;
            }
            else {
                sRow = midRow + 1;
            }
        }
        return false;
    }
};