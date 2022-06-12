/*
Problem Statement: Given the heads of two singly linked-lists headA and headB, 
return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Examples:

Example 1:

Input:
List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:
2
Explanation: Here, both lists intersecting nodes start from node 2.

Example 2:

Input:
 List1 = [1,2,7], List 2 = [2,8,1]
Output:
 Null
Explanation: Here, both lists do not intersect and thus no intersection node is present.


*/

//******** Brute force *******

//utility function to check presence of intersection
node* intersectionPresent(node* head1,node* head2) {
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}

// Time Complexity: O(m*n) reason: For each node in list 2 entire lists 1 are iterated. 
// Space Complexity: O(1)






//******* Hashing *********

node* intersectionPresent(node* head1,node* head2) {
    unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}

// Time Complexity: O(n+m) Reason: Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m). 
// Space Complexity: O(n) Reason: Storing list 1 node addresses in unordered_set.




//****** Optimised Solution *******

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode* h1 = head1;
        ListNode* h2 = head2;
        while(h1 != h2) {
            if(h1 == NULL) h1 = head2;
            else h1 = h1->next;

            if(h2 == NULL) h2 = head1;
            else h2 = h2->next;
        }
        return h1;
      
    }
};

// Time Complexity: O(2*max(length of list1,length of list2)) Reason: Uses the same concept of difference of lengths of two lists.
// Space Complexity: O(1)

