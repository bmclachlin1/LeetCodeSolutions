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
    bool hasPathSum(TreeNode* root, int sum) {
        // not a node, just return false
        if (root == NULL) return false;
        
        // we hit a leaf node, so check if sum equals data in our node
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val) {
                return true;
            }
            return false;
        }
        
        // check left subtree, passing the new sum as sum minus data in our node
        if (hasPathSum(root->left, sum - root->val)) {
            return true;
        }
            
        // check right subtree, passing the new sum as sum minus data in our node
        if (hasPathSum(root->right, sum - root->val)) {
            return true;
        }
        
        return false;
    }
};