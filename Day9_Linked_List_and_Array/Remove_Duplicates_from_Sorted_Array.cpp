/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that 
each unique element appears only once. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have 
the result be placed in the first part of the array nums. More formally, if there are k elements 
after removing the duplicates, then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.
 
Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

//******* Brute Force *******
/*
*ALGORITHM :
    -> Declare a HashSet.
    -> Run a for loop from starting to the end.
    -> Put every element of the array in the set.
    -> Store size of the set in a variable K.
    -> Now put all elements of the set in the array from the starting of the array.
    -> Return K.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        set<int> set;
        for(int i = 0; i < arr.size(); i++) {
            set.insert(arr[i]);
        }
        int k = set.size();
        int j = 0;
        for(int x: set) {
            arr[j++] = x;
        }
        return k;
    }
};

// Time complexity: O(n * log(n)) + O(n)
// Space Complexity: O(n) 




//******* Two Pointers ********

/*
* ALGORITHM
    -> Take a variable i as 0;
    -> Use a for loop by using a variable ‘j’ from 1 to length of the array.
    -> If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
    -> After completion of the loop return i+1, i.e size of the array of unique elements.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

// Time complexity: O(n)
// Space Complexity: O(1)