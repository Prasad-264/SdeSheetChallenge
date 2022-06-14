/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/

//******* Brute force ********

class Solution {
public :
    int trap(vector < int > & arr) {
        int n = arr.size();
        int waterTrapped = 0;
        for(int i = 0; i < n; i++) {
            int j = i;
            int leftMax = 0, rightMax = 0;
            while (j >= 0) {
                leftMax = max(leftMax, arr[j]);
                j--;
            }
            j = i;
            while (j < n) {
                rightMax = max(rightMax, arr[j]);
                j++;
            }
            waterTrapped += min(leftMax, rightMax) - arr[i];
        }
        return waterTrapped;
    }
};

// Time Complexity: O(N*N) as for each index we are calculating leftMax and rightMax so it is a nested loop.
// Space Complexity: O(1).




//****** Better Solution ******

class solution {
public:
    int trap(vector < int > & arr) {
        int n = arr.size();
        int prefix[n], suffix[n];

        prefix[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], arr[i]);
        }

        suffix[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], arr[i]);
        }

        int waterTrapped = 0;
        for(int i = 0; i < n; i++) {
            waterTrapped += min(prefix[i], suffix[i]) - arr[i];
        }
        return waterTrapped;
    }
}

// Time Complexity : O(3*N) as we are traversing through the array only once. And O(2*N) for computing prefix and suffix array.
// Space Complexity : O(N) + O(N) for prefix and suffix arrays.




//******* Optimised Solution (2 pointers) **********

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, water = 0;
        int leftMax = 0, rightMax = 0;
        while(l<=r) {
            if(height[l] <= height[r]) {
                if(height[l] > leftMax) leftMax = height[l];
                else water += (leftMax - height[l]);
                l++;
            }
            else {
                if(height[r] > rightMax) rightMax = height[r];
                else water += (rightMax - height[r]);
                r--;
            }
        }
        return water;
    }
};

// Time Complexity: O(N) because we are using 2 pointer approach.
// Space Complexity: O(1) because we are not using anything extra.