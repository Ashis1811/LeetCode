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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = even;
        while(even && even->next)
        {
            odd->next = even->next; // move odd to next of even 
            odd = odd->next; // move odd forward

            even->next = odd->next; // move even to next of odd
            even = even->next; // move even forward
        }
        odd->next = evenhead; // link odd to even
        return head;
    }
};