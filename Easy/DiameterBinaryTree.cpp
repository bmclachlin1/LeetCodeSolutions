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
    int ans = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        int d = depth(root);
        return ans;
    }
    
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // recurse on left and right subtrees
        int left = depth(root->left);
        int right = depth(root->right);
        
        ans = max(ans, left + right);
        
        return max(left, right) + 1;
        
    }
};