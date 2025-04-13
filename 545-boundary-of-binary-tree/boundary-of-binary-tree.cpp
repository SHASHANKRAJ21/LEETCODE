/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return (node != nullptr && node->left == nullptr && node->right == nullptr);
    }

    // Function to add left boundary nodes (excluding leaf nodes)
    void addleftboundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) { // Add non-leaf node to result
                res.push_back(curr->val);
            }
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    // Function to add right boundary nodes (excluding leaf nodes)
    void addrightboundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->right;
        vector<int> tmp;
        while (curr) {
            if (!isLeaf(curr)) { // Add non-leaf node to temporary result
                tmp.push_back(curr->val);
            }
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        // Add right boundary nodes in reverse order
        for (int i = tmp.size() - 1; i >= 0; --i) {
            res.push_back(tmp[i]);
        }
    }

    // Function to add leaf nodes
    void addleaves(TreeNode* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        if (root->left) {
            addleaves(root->left, res);
        }
        if (root->right) {
            addleaves(root->right, res);
        }
    }

    // Main function to get boundary of the binary tree
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        if (!isLeaf(root)) {
            res.push_back(root->val); // Add root to the result if it's not a leaf
        }
        addleftboundary(root, res);  // Add left boundary
        addleaves(root, res);        // Add leaves
        addrightboundary(root, res); // Add right boundary
        return res;
    }
};
