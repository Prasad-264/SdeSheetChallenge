/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]

Example 2:

Input: nums = [1]
Output: [1]

Example 3:

Input: nums = [1,2]
Output: [1,2]
*/

//* Hashing (Maping)

vector<int> majorityElement(int arr[], int n) {
    unordered_map < int, int > mp;
    vector < int > ans;

    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    for (auto x: mp) {
        if (x.second > (n / 3))
        ans.push_back(x.first);
    }
    return ans;
}

// TC = O(N)
// SC = O(N)


//* Optimal Solution (Extended Boyer Moore’s Voting Algorithm)
class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int y = -1, z = -1, cy = 0, cz = 0;
        for (const auto & x: a)  {
		    if (x == y) cy++;
		    else if (x == z) cz++;
		    else if (! cy) y = x, cy = 1;
		    else if (! cz) z = x, cz = 1;
		    else cy--, cz--;
        }      
        cy = cz = 0;
        for (const auto & x: a)
    		 if (x == y) cy++;
			 else if (x == z) cz++;
  
	    vector<int> r;
	    if (cy > a.size()/3) r.push_back(y);
	    if (cz > a.size()/3) r.push_back(z);
	    return r;
    }
};

// TC = O(N)
// SC = O(1)
