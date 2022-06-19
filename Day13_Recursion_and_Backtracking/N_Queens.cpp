/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen 
and an empty space, respectively.

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:

Input: n = 1
Output: [["Q"]]
*/

//****** 

class Solution {
public:
    bool isSafe1(int row, int col, vector < string > board, int n) {
        // check upper element
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
            return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;
        while (col >= 0) {
            if (board[row][col] == 'Q')
            return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
            return false;
            row++;
            col--;
        }
        return true;
    }

public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe1(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
            }
        }
    }

public:
    vector < vector < string >> solveNQueens(int n) {
        vector < vector < string >> ans;
        vector < string > board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};

// Time Complexity: Exponential in nature, since we are trying out all ways. To be precise it goes as O(N! * N) nearly.
// Space Complexity: O(N^2)



class Solution {
private:
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& left,vector<int>& upperDiagonal, 
    vector<int>& lowerDiagonal, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        for( int row=0; row<n; row++) {
            if(left[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0) {
                board[row][col] = 'Q';
                left[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1, board, ans, left, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                left[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0; i<n; i++) board[i] = s;
        vector<int> left(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
        solve(0, board, ans, left, upperDiagonal, lowerDiagonal, n);
        return ans;        
    }
};

// Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).
// Space Complexity: O(N)

