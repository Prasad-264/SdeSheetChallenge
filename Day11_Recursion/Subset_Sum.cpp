/*

Given a list arr of N integers, print sums of all subsets in it. 

Example 1:

Input:
    N = 2
    arr[] = {2, 3}
Output:
    0 2 3 5
Explanation:
    When no elements is taken then Sum = 0.
    When only 2 is taken then Sum = 2.
    When only 3 is taken then Sum = 3.
    When element 2 and 3 are taken then Sum = 2+3 = 5.

Example 2:

Input:
    N = 3
    arr = {5, 2, 1}
Output:
    0 1 2 3 5 6 7 8
*/


class Solution {
private:
    void func(int ind, int sum, vector<int>& arr, int N, vector<int>& ds) {
        if(ind == N) {
            ds.push_back(sum);
            return;
        }
        // Pick element and add to Sum..!
        func(ind+1, sum + arr[ind], arr, N, ds);
        // Not pick element..!
        func(ind+1, sum, arr, N, ds);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ds;
        func(0, 0, arr, N, ds);
        return ds;
        
    }
};

/*
Time Complexity: O(2^n) + O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. 
                So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
*/