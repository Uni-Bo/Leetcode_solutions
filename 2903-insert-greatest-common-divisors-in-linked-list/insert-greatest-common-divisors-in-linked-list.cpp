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
int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a < b) {
        swap(a, b);
    }
    int m = a % b;
    return gcd(b, m);
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr ||head->next==nullptr) return head;
        ListNode*ptr=head;
        ListNode*nxt=head->next;
        while(nxt!=nullptr){
            int g=gcd(ptr->val,nxt->val);
            ListNode*temp=new ListNode(g);
            ptr->next=temp;
            temp->next=nxt;
            ptr=nxt;
            nxt=nxt->next;
        }
        return head;
        
    }
};