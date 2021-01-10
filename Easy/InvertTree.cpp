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
    TreeNode* invertTree(TreeNode* root) {
        // inverse of empty tree is empty tree
        if (root == NULL) return root;
        
        // recursively solve left and right subtrees
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        
        // above will do nothing unless after doing the recursive call you change left to right
        // and right to left
        swap(root->left, root->right);
        
        return root;    
        
    }
};