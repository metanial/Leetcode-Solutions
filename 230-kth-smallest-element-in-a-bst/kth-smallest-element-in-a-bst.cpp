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
    void inorder(TreeNode* root, vector<int> &sorted) {
        if(root->left != nullptr) inorder(root->left, sorted);
        sorted.push_back(root->val);
        if(root->right != nullptr) inorder(root->right, sorted);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return -1;
        vector<int> sorted;
        inorder(root, sorted);
        return sorted[k-1];
    }
};