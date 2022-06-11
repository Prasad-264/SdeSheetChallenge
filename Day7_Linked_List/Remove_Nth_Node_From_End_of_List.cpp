/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]
*/

/*
Solution 1: Naive Approach [Traverse 2 times]

    Intuition: We can traverse through the Linked List while maintaining a count of nodes, let’s say in variable count , 
and then traversing for the 2nd time for (n – count) nodes to get to the nth node of the list.
*/

//* Solution 2: [Efficient] Two pointer method

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        for(int i = 0; i < n; i++) fast = fast->next;
        
        if(fast == NULL) return head->next;
        
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        } 
        slow->next = slow->next->next;
        return head;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)