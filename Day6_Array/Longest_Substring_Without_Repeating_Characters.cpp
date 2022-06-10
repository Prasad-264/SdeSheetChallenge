/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

//* Brute force Approach
int solve(string str) {
    int maxans = INT_MIN;
    for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
    {
        unordered_set < int > set;
        for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
        {
            if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
            {
                maxans = max(maxans, j - i);
                break;
            }
            set.insert(str[j]);
        }
    }
    return maxans;
}

// Time Complexity : O(N*N)
// Space Complexity : O(N)

//* Optimised Approach 1

int solve(string str) {
    int maxans = INT_MIN;
    unordered_set < int > set;
    int l = 0;
    for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
    {
        if (set.find(str[r]) != set.end()) //if duplicate element is found
        {
            while (l < r && set.find(str[r]) != set.end()) {
                set.erase(str[l]);
                l++;
            }
        }
        set.insert(str[r]);
        maxans = max(maxans, r - l + 1);
    }
    return maxans;
}

// Time Complexity : O(2N)
// Space Complexity : O(N)

//* Optimised Approch 2

class Solution {
public:
    int lengthofLongestSubstring(string s) {
        vector < int > mpp(256, -1);
        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        while (right < n) {
            if (mpp[s[right]] != -1)
            left = max(mpp[s[right]] + 1, left);

            mpp[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};

or

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(256)