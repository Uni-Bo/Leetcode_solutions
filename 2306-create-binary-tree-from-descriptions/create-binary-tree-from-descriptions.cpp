/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>tree;
        set<int>p;
        set<int>c;
        for(auto& desc:descriptions)
        {
            p.insert(desc[0]);
            c.insert(desc[1]);
            if(tree.find(desc[0])==tree.end())
                tree[desc[0]]=new TreeNode(desc[0]);

            if(tree.find(desc[1])==tree.end())
                tree[desc[1]]=new TreeNode(desc[1]);

            if(desc[2]==1)
            {
                tree[desc[0]]->left=tree[desc[1]];
            }
            else
                tree[desc[0]]->right=tree[desc[1]];
        
        }
    vector<int>root;
    set_difference(p.begin(), p.end(), c.begin(), c.end(), back_inserter(root));

    return tree[root[0]];
    }
};