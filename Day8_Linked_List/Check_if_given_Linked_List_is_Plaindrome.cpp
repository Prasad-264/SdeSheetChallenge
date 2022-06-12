/*
Given the head of a singly linked list, return true if it is a palindrome.

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false
*/

//******* Using extra Space *******

bool isPalindrome(node* head) {
    vector<int> arr;
    while(head != NULL) {
        arr.push_back(head->num);
        head = head->next;
    }
    for(int i=0;i<arr.size()/2;i++) 
        if(arr[i] != arr[arr.size()-i-1]) return false;
    return true;
}

// Time Complexity: O(N) Reason: Iterating through the list to store elements in the array.
// Space Complexity: O(N) Reason: Using an array to store list elements for further computations.

//******** Optimized Solution ********

class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        while(head != NULL) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        slow = slow->next;
        while(slow != NULL) {
            if(temp->val != slow->val) return false;
            slow = slow->next;
            temp = temp->next;
        }
        return true;
    }
};

// Time Complexity: O(N/2)+O(N/2)+O(N/2)

Reason: O(N/2) for finding the middle element, reversing the list from the middle element, 
and traversing again to find palindrome respectively.

//Space Complexity: O(1)