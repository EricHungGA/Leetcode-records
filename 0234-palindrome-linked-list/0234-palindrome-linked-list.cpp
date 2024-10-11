/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // two pointer approach but with linked list using head and tail
        // use arrays to store val
        // reach middle by using slow and fast pointers then compare arrays
        vector<int>front;
        vector<int>back;
        
        // edge case if its empty or one node
        if(!head || !head->next)return true;
        ListNode* slow = head;
        ListNode* fast = head;
        // get the middle (slow ptr) and end
        while(fast && fast->next){
            front.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        // check for odd length lists
        if(fast){
            slow = slow->next;
        }
        
        while(slow){
            back.push_back(slow->val);
            slow = slow->next;
        }
        
        // now use two pointers
        // one is from the left of our front vect
        // one is from the right end of our back vect
        int l = 0;
        int r = back.size() - 1;
        while(l < front.size() && r >= 0){
            if(front[l] != back[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};