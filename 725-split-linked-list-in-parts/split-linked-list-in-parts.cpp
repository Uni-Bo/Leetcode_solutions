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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* ptr = head;
        
        while (ptr) {
            n++;
            ptr = ptr->next;
        }

        int partSize = n/k;
        int remainder = n % k;

        vector<ListNode*> ans(k, nullptr);
        ptr = head;

        for (int i = 0; i < k && ptr; ++i) {
            ans[i] = ptr;
            int curr = partSize + (remainder > 0 ? 1 : 0);
            remainder--;
            
            for (int j = 1; j < curr; ++j) {
                ptr = ptr->next;
            }

            ListNode* next = ptr->next;
            ptr->next = nullptr;
            ptr = next;
        }

        return ans;
    }
};
