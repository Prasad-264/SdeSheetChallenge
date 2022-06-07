/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Input: matrix = [1  2  3]                [7  4  1] 
                [4  5  6]      ===>      [8  5  2]
                [7  8  9]                [9  6  3]
                
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose the Original matrix 
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) 
                swap(matrix[i][j], matrix[j][i]);
        }
        
        // Reverse the transposed matrix or reverse the rows  
        for(int i=0; i<n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
        
    }
};

//* TC = O(N*N)
//* SC = O(1)

//* Rotate in Anticlock direction

class Solution {   
public:
    void rotateby90(vector<vector<int> >& matrix, int n) {
        // reverse the each row
        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        // transpose the matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    } 
};