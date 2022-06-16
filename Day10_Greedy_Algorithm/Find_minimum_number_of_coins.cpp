/*
Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N.


Example 1:

Input: N = 43
Output: 20 20 2 1
Explaination: 
Minimum number of coins and notes needed  to make 43. 

Example 2:

Input: N = 1000
Output: 500 500
Explaination: minimum possible notes is 2 notes of 500.
*/

class Solution{
public:
    vector<int> minPartition(int V) {
        vector<int> deno = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int n = deno.size();
        
        vector<int> ans;
        for(int i = n-1; i>=0; i--) {
            while(V >= deno[i]) {
                V -= deno[i];
                ans.push_back(deno[i]);
            }
        }
        return ans;
    }
};

// Time Complexity:O(V)
// Space Complexity:O(1)