/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

//******* Recursive Solution Using hashset *******

class Solution {
public:
    void fun(vector<int>& nums, int index, vector<int> ds, set<vector<int>>& res) {
        if(index == nums.size()) {
            sort(ds.begin(), ds.end());
            res.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        fun(nums, index + 1, ds, res);
        ds.pop_back();
        fun(nums, index + 1, ds, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> ds;
        fun(nums, 0, ds, res);
        for(auto it = res.begin(); it != res.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};

// Time Complexity: O( 2^n *(k log (x) )).
// Space Complexity:  O(2^n * k)





//******* Recursive Solution without using hashset *******

class Solution {
public:
    void func(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);
        for(int i = ind; i < nums.size(); i++) {
            if(i != ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            func(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        func(0, nums, ds, ans);
        return ans;
        
    }
};

// Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure 
                    // if the average length of every subset is k. Overall O(k * 2^n).
// Space Complexity: O(2^n * k)

