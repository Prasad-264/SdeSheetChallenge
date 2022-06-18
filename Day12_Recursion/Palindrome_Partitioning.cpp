/*
Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward. 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:

Input: s = "a"
Output: [["a"]]
*/


class Solution {
private: 
    
    void partition(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        int n = s.length();
        
        if (start == n) {
            result.push_back(path);
            return;
        } 
        
        for(int i = start; i < n; i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                partition(s, i + 1, path, result);
                path.pop_back();  //Tode ho toh jodna to padega he...!
            }
        }
        
    }
    
    // Check Palindrome or not..!
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        partition(s, 0, path, result);
        return result;
    }
};



/*

* Time Complexity: O( (2^n) *k*(n/2) )

Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. 
    O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

* Space Complexity: O(k * x)

Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the 
    list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion 
    tree is n, so the auxiliary space required is equal to the O(n).
*/