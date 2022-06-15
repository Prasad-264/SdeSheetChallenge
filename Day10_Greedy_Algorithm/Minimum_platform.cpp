/*
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of 
platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure 
time can never be the same for a train but we can have arrival time of one train equal to departure time 
of the other. At any given instance of time, same platform can not be used for both departure of a train 
and arrival of another train. In such cases, we need different platforms.

Example 1:

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.

Example 2:

Input: n = 3
arr[] = {0900, 1100, 1235}
dep[] = {1000, 1200, 1240}
Output: 1
Explanation: Only 1 platform is required to 
safely manage the arrival and departure 
of all trains. 
*/

//****** Brute Force ******

class Solution {
public:
    int countPlatforms(int n, int arr[], int dep[]) {
        int ans = 1; //final value
        for(int i=0; i<=n-1; i++) {
            int count = 1; // count of overlapping interval of only this   iteration
            for(int j=i+1; j<=n-1; j++) {
                if((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i])) {
                    count++;
                }
            }
            ans = max(ans, count); //updating the value
        }
        return ans;
    }
};

// Time Complexity: O(n^2)  (due to two nested loops).
// Space Complexity: O(1)  (no extra space used).




//******* Optimal Solution (Sorting and then 2 pointer) *******

class Solution {
public:
    int findPlatform(int arr[], int dep[], int n) {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int plat_needed = 1, result = 1;
    	int i = 1, j = 0;
    	while(i < n && j < n) {
    	    if(arr[i] <= dep[j]) {
    	        plat_needed++;
    	        i++;
    	    }
    	    else if(arr[i] > dep[j]) {
    	        plat_needed--;
    	        j++;
    	    }
    	   // if(plat_needed > result) {
    	   //     result = plat_needed;
    	   // }
    	   result = max(result, plat_needed);
    	}
    	return result;
    }
};

// Time Complexity: O(nlogn) Sorting takes O(nlogn) and traversal of arrays takes O(n) so overall time complexity is O(nlogn).
// Space complexity: O(1)  