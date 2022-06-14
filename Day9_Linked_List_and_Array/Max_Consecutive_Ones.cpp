/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int max_count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) ans++;
            else ans = 0;
            max_count = max(max_count, ans);
        }
        return max_count;
    }
};

// Time Complexity: O(N) since the solution involves only a single pass.
// Space Complexity: O(1) because no extra space is used.