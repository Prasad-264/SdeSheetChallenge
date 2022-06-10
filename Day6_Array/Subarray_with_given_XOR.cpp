/*
Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equals to B.

Example Input
Input 1:
 A = [4, 2, 2, 6, 4]
 B = 6
Output 1:
 4
Explanation 1:
 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

Input 2:
 A = [5, 6, 7, 8, 9]
 B = 5
Output 2:
 2
Explanation 2:
 The subarrays having XOR of their elements as 2 are [5] and [5, 6, 7, 8, 9]
*/

//********* Brute force

class Solution { 
public:
    int solve(vector<int> &A, int B) {
        long long c = 0;
        for(int i=0; i<A.size(); i++) {
            int current_xor = 0;
            for(int j=i; j<A.size(); j++) {
                current_xor ^= A[j];
                if(current_xor == B) c++;
            }
        }
        return c;
    }
};

// Time Complexity: O(N*N)
// Space Complexity: O(1)

//************ Prefix xor and map

class Solution {
public:
    int solve(vector<int> &A, int B) {
        unordered_map<int,int> visited;
        int cpx = 0;
        long long c = 0;
        for(int i=0; i<A.size(); i++) {
            cpx ^= A[i];
            if(cpx == B) c++;
            int h = cpx ^ B;
            if(visited.find(h) != visited.end()) {
                c = c + visited[h];
            }
            visited[cpx]++;
        }
        return c;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)