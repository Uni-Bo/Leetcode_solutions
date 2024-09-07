class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true; // Reached the end of the linked list
        }
        if (root == nullptr) {
            return false; // Reached a null node in the tree but haven't finished the linked list
        }
        if (head->val != root->val) {
            return false; // Values don't match
        }
        // Continue to check both left and right subtrees
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        // Start from the current node or any of the subtrees
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
