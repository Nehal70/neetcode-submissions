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
    ListNode* reverseList(ListNode* head) {
        //create a fake haed
        if (head == NULL) return NULL;
        ListNode* newHead = head;
        ListNode* curr = head->next; // iterator
        while (curr) {
            ListNode* temp = curr->next; // save curr->next
            head->next = temp; //make head's next curr's next
            curr->next = newHead; //put curr ahead of the newHead
            //newHead update
            newHead = curr;
            //update for next iteration
            curr = head->next;
        }
        return newHead;
    }
};
