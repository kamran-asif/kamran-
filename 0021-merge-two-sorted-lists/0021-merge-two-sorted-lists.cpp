w/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <queue>
#include <vector>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // comparator for min heap
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
      };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

       // heads ko heap me dalo
        if (list1) pq.push(list1);
        if (list2) pq.push(list2);

        // dummy node for the result list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // jb tk heap empty nhi h
        while (!pq.empty()) {
            //smallest node uthao
            ListNode* node = pq.top();
            pq.pop();

            // attach in result
            tail->next = node;
            tail = tail->next;
            // if next node exist then try to push on heap
            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};
