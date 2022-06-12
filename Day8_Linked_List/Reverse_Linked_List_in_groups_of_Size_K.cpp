/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is 
not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/

//****** Recursive Solution ********

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == NULL) return head;
            cursor = cursor->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = NULL;
        for(int i=0; i<k; i++) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        //if(temp != NULL) {
        head->next = reverseKGroup(curr, k);
        //}
        return prev;
    }
};

//******* Iterative Solution ********

//utility function to find length of the list
int lengthOfLinkedList(node* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}

//utility function to reverse k nodes in the list
node* reverseKNodes(node* head,int k) {
    if(head == NULL || head->next == NULL) return head;    
    int length = lengthOfLinkedList(head);
    
    node* dummyHead = new node(0);
    dummyHead->next = head;
    
    node* pre = dummyHead;
    node* cur;
    node* nex;
    
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
}

// Time Complexity: O(N) Reason: Nested iteration with O((N/k)*k) which makes it equal to O(N).
// Space Complexity: O(1)