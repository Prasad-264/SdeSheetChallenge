/*
You are given a read-only array of N integers with values also in the range [1,N] both inclusive. 
Each integer appears exactly once except A which appears twice and B which is missing. 
The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

Example 1:

Input Format:  array[] = {3,1,2,5,3}
Result: {3,4)

Explanation: A = 3 , B = 4 
Since 3 is appearing twice and 4 is missing

Example 2:

Input Format: array[] = {3,1,2,5,4,6,7,5}
Result: {5,8)

Explanation: A = 5 , B = 8 
Since 5 is appearing twice and 8 is missing
*/

pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
    pair<int, int> p;
    vector<int> freq(n+1, 0);
    for(auto i : arr) freq[i]++;
    
    for(int i=1; i<n+1; i++) {
        if(freq[i] == 0) p.first = i;
        if(freq[i] > 1) p.second = i;
    }
    return p;
}

// TC = O(N)
// SC = O(N)