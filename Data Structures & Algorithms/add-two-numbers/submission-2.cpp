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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //edge case
        if (l1 == nullptr || l2 == nullptr) {
            return nullptr;
        }
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* result = new ListNode(0);
        ListNode* resultCurr = result;
        int carry = 0;
        while (curr1 || curr2) {
            int sum = 0;
            if (!curr1) { sum = carry + curr2->val; resultCurr->next = new ListNode((sum) % 10); curr2 = curr2->next;}
            else if (!curr2) { sum = carry + curr1->val; resultCurr->next = new ListNode((sum) % 10); curr1 = curr1->next;}
            else { sum = carry + curr1->val + curr2->val; resultCurr->next = new ListNode((sum) % 10); curr1 = curr1->next; curr2 = curr2->next;}
            carry = (sum) / 10;
            resultCurr = resultCurr->next;
        }
        if (carry != 0) resultCurr->next = new ListNode(carry); 
        return result->next;
    }
};
