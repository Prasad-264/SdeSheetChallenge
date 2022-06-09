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

// GFG problem
/*
Given a matrix mat[][] of size N x M, where every row and column is sorted in increasing order, 
and a number X is given. The task is to find whether element X is present in the matrix or not.

Example 1:

Input:
N = 3, M = 3
mat[][] = 3 30 38 
         44 52 54 
         57 60 69
X = 62
Output: 0
Explanation:
62 is not present in the
matrix, so output is 0

Example 2:

Input:
N = 1, M = 6
mat[][] = 18 21 27 38 55 67
X = 55
Output: 1
Explanation:
55 is present in the
matrix at 5th cell.
*/

class Solution {
public:	
	int matSearch(vector<vector<int>>& mat, int n, int m, int x) {
	    int i = 0, j = m - 1;
	    while(i < n && j >= 0) {
	        if(mat[i][j] == x) return 1;
	        else if(mat[i][j] > x) j--;
	        else i++;
	    }
	    return 0;
	}
};

//* TC = O(log(m*n))
//* SC = O(1)