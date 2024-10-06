/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // edge case but also avoids accidentally accessing the next of an empty list
        if(head == NULL || head->next == NULL){
            return false;
        }
            // two pointers, one slow (moves by 1) and one fast (moves by 2)
            ListNode *slow = head;
            ListNode *fast = head->next;
            while(slow != fast){
                if(fast == NULL || fast->next == NULL){
                    // checking to see if it reached the end aka non circle scenario
                    return false;
                }
                slow = slow->next;
                fast = fast->next->next;
            }
            // this means that fast caught up to slow, indicating a circle
            return true;
        }
};