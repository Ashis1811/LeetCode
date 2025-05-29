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
    #define pi pair<int, ListNode*>
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pi,  vector<pi>, greater<pi>> pq;
        int n = lists.size();
        for(int i = 0; i < n; i++)
        {
            if(lists[i])
            {
                pq.push({lists[i]->val, lists[i]});
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(! pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            temp->next = it.second;
            temp = temp->next;
            if(it.second->next)
            {
                pq.push({it.second->next->val, it.second->next});
            }
        }
        return dummy->next;
    }
};