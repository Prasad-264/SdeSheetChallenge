/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]
*/

//****** Recursive with extra space ********

class Solution {
private:
    void recurPermute(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, int freq[]) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()] = {0};
        //for (int i = 0; i < nums.size(); i++) freq[i] = 0;
        recurPermute(ds, nums, ans, freq);
        return ans;
    }
};

// Time Complexity:  N! x N
// Space Complexity:  O(N)




//******* Backtracking *********

class Solution {
public:
    void func(int ind, vector<int>& nums, vector<vector<int>>& ans) {
        if(ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int i = ind; i<nums.size(); i++) {
            swap(nums[ind], nums[i]);
            func(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        func(0, nums, ans);
        return ans;        
    }
};

// Time Complexity: O(N! X N)
// Space Complexity: O(1)



//******* For string ********

class solution {
private:
    void func(int ind, string& s, vector<string>& ans) {
        if(ind == s.size()) {
            ans.push_back(s);
            return;
        }

        for(int i = ind; i<s.size(); i++) {
            swap(s[ind], s[i]);
            func(ind+1, s, ans);
            swap(s[ind], s[i]);
        }
    }
public:
    vector<string> findPermutations(string &s) {
        vector<string> ans;
        func(0, s, ans);
        return ans;    
    }
};

// Time Complexity: O(N! X N)
// Space Complexity: O(1)
