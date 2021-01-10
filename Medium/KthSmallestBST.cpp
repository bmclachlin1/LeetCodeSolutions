//////////////////////////////////////////////////////////////////////////////////////////////////
// BST has property that an inorder traversal will go through the elements in ascending order.
// Then, we can do an inorder traversal to form a list of the elements in ascending order.
// Since arrays are indexed starting at 0, we grab the element at index k-1 (this will be kth
// smallest element).
//////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    // helper function to traverse tree inorder and return result as an array
    vector<int> inorder(TreeNode* root, vector<int> &elements) {
        if (root == nullptr) return elements;
        inorder(root->left, elements);
        elements.push_back(root->val);
        inorder(root->right, elements);
        return elements;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        vector<int> elems = inorder(root, temp);
        return elems[k-1];
    }
};