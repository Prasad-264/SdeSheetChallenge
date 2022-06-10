/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
*/

//* Naive Approch

class Solution {
public :
    int solve(vector<int>& a) {
        int  max = 0;
        for(int i = 0; i < a.size(); ++i) {
            int sum = 0;
            for(int j = i; j < a.size(); ++j) {
                sum += a[j];
                if(sum == 0) {
                    max = max(max, j-i+1);
                }
            }
        }
	    return max;
   }
};

// Time Complexity: O(N*N)
// Space Complexity: O(1) 


//* optimal Approch

class Solution {
public:
    int maxLen(vector<int>& arr, int n) {   
        unordered_map<int,int> mpp; 
        int maxi = 0;
        int sum = 0; 
        for(int i=0; i<n; i++) {
            sum += arr[i]; 
            if(sum == 0) {
                maxi = i + 1; 
            }
            else {
                if(mpp.find(sum) != mpp.end()) {
                    maxi = max(maxi, i - mpp[sum]); 
                }
                else {
                    mpp[sum] = i;
                }
            }   
        }
        return maxi;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N) 