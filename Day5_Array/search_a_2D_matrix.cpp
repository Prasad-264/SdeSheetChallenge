/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true


Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/

//* Naive approch (brute force)

bool findTargetInMatrix(vector<vector<int>>& mat, int m, int n, int target) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(mat[i][j] == target) return true;
        }
    }
    return false;
}

//* TC = O(m*n)
//* SC = O(1)

//* Binary Search (optimal approch)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows*cols;
        int start = 0;
        int end = n-1;
        while(start <= end ) {
            int mid = (start + end) >> 1;
            int element = matrix[mid/cols][mid%cols];
            if(element == target) return true;
            else if(element > target) end = mid-1;
            else start = mid+1;
        }
        return false;
    }
};

//* TC = O(log(m*n))
//* SC = O(1)
