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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxpathsum(root,maxi);
        return maxi;
        
    }
    int maxpathsum(TreeNode*node,int &maxi){
        if(node==nullptr){
            return 0;
        }
        int lh=max(0,maxpathsum(node->left,maxi));
        int rh=max(0,maxpathsum(node->right,maxi));
        maxi=max(maxi,lh+rh+node->val);
        return node->val+max(lh,rh);
    }
};