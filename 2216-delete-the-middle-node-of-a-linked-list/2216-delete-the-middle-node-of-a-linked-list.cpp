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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            head = NULL;
            return head;
        }
        ListNode* curr = head;
        int n = 0;
        while(curr != NULL)
        {
            n++;
            curr = curr->next;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* track = NULL;
        if(n % 2 != 0)
        {
            while(temp != slow)
            {
                if(temp->next == slow)
                {
                    track = temp;
                    break;
                }
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        else
        {
            while(slow != temp)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        return head;
    }
};