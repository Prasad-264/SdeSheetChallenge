/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
*/

//********* Sorting method ************

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n - 1; i++) {
            if(arr[i] == arr[i + 1]) {
                return arr[i];
            }
        }
    }
};

// TC = O(N*log N)
// SC = O(1)

//********* Using frequency array ************

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        for(int i = 0; i < n; i++) {
            if(freq[nums[i]] == 0) freq[nums[i]]++;
            else return nums[i];
        }
        return 0;
    }
};

// TC = O(N)
// SC = O(N)

//********* swaping method ************

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};

// TC = O(N)
// SC = O(1)