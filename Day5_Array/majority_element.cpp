/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

//* hashing (Brute force solution)

class Solution {
public:
    int majorityElement(vector<int>& arr) {
    unordered_map<int,int> m;
        for(auto x : arr) {
            m[x]++;
            if(m[x] > arr.size()/2) {
                return x;
            }
        }
        return 0;
    }
};

// TC = O(N)
// SC = O(N)



//* Moore's Voting algrithm (Efficient solution)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0, majority = 0;
        for(int num : nums) {
            if(counter == 0) majority = num;
            if(num == majority) counter++;
            else counter--;
        }
        return majority;
    }
};

// TC = O(N)
// SC = O(1)