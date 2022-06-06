/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example 1:

Input: matrix =  [1,1,1]
                 [1,0,1]
                 [1,1,1]

Output:          [1,0,1]
                 [0,0,0]
                 [1,0,1]

Example 2:

Input: matrix =  [0,1,2,0]
                 [3,4,5,2]
                 [1,3,1,5]

Output:          [0,0,0,0]
                 [0,4,5,0]
                 [0,3,1,0]
*/


// Using TC - O(n*m) + O(n*m) and SC - O(n + m)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> row(n, 0), col(m, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = -1;
                    col[j] = -1;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(row[i] == -1 || col[j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Using TC - 2 * O(n*m) and SC - O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1;
        
        for (int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < m; j++) {
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;           // make 1 row and 1 col as dummy array
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 1; j--) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
                if(col0 == 0) matrix[i][0] = 0;
            }
        }
    }
};