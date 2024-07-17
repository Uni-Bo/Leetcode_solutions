

class Solution {
public:
    void mapNodes(TreeNode* root, unordered_map<int, TreeNode*>& nodes) {
        if (!root) return;
        nodes[root->val] = root;
        mapNodes(root->left, nodes);
        mapNodes(root->right, nodes);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) return {};

        unordered_map<int, TreeNode*> nodes;
        unordered_set<TreeNode*> remainingRoots;
        mapNodes(root, nodes);
        remainingRoots.insert(root);

        for (int val : to_delete) {
            if (nodes.find(val) != nodes.end()) {
                TreeNode* nodeToDelete = nodes[val];
                
                if (remainingRoots.find(nodeToDelete) != remainingRoots.end()) {
                    remainingRoots.erase(nodeToDelete);
                }
                
                if (nodeToDelete->left) {
                    remainingRoots.insert(nodeToDelete->left);
                }
                if (nodeToDelete->right) {
                    remainingRoots.insert(nodeToDelete->right);
                }

                // Disconnect the node from its parent
                if (nodeToDelete == root) {
                    root = nullptr;
                } else {
                    for (auto& pair : nodes) {
                        if (pair.second->left == nodeToDelete) {
                            pair.second->left = nullptr;
                        }
                        if (pair.second->right == nodeToDelete) {
                            pair.second->right = nullptr;
                        }
                    }
                }
                
                nodes.erase(val);
                delete nodeToDelete;  // Ensure no further access to this node
            }
        }

        vector<TreeNode*> result(remainingRoots.begin(), remainingRoots.end());
        return result;
    }
};
