/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either 
down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    1. Right -> Down -> Down
    2. Down -> Down -> Right
    3. Down -> Right -> Down
*/

//* Recursive solution (TLE on leetcode)

class Solution {
private :
    int countPath(int i,int j, int m, int n) {
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        int right = countPath(i+1, j, m, n);
        int down = countPath(i, j+1, m, n);
        return right + down;
    }
public:
    int uniquePaths(int m, int n) {
        return countPath(0, 0, m, n);
    }
};

// TC = The time complexity of this recursive solution is exponential.
// SC = space complexity is also exponential as it stores recursive stack space.


//* Dynamic Programming Solution

class Solution {
private :
    int countPath(int i,int j, int m, int n, vector<vector<int>>& dp) {
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = countPath(i+1, j, m, n, dp) + countPath(i, j+1, m, n, dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        int num = countPath(0, 0, m, n, dp);
        if(m == 1 && n == 1) return num;
        return dp[0][0];
    }
};

// TC = O(n*m);
// sC = O(n*m);

