/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output:         [1]
               [1,1]
              [1,2,1]
             [1,3,3,1]
            [1,4,6,4,1]

Example 2:

Input: numRows = 1
Output: [[1]]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0; i<numRows; i++) {
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            for(int j=1; j<i; j++) {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};

//* For returning a perticular row of given num

/*
Example 1:

Input:
N = 4
Output: 1 3 3 1
Explanation: 4th row of pascal's triangle
is 1 3 3 1.

Example 2:

Input:
N = 5
Output: 1 4 6 4 1
Explanation: 5th row of pascal's triangle
is 1 4 6 4 1.

*/

class Solution {
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<ll> ans = {1};
        ll res = 1;
        for(ll i=0; i<n-1; i++) {
            res *= (n-i-1);
            res /= (i+1);
            ans.push_back(res);
        }
        return ans;
    }
};

