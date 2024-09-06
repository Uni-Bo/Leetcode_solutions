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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>set;
        set.insert(nums.begin(),nums.end());
        ListNode*ptr=head,*prev=nullptr;
        while(ptr!=nullptr)
        {
            if(set.find(ptr->val)!=set.end())
            {
                if(ptr==head)
                {
                    head=head->next;
                    ptr=head;
                }
                else
                {
                    prev->next=ptr->next;
                    ptr=prev->next;
                }
            }
            else
            {
                prev=ptr;
                ptr=ptr->next;
            }
        }
        return head;
        
    }
};