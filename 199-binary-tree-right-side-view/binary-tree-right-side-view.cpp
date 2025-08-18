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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        vector<int> rightSide;

        q.push(root);
        while(!q.empty()) {
            int lastNodeVal;
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->left != nullptr) q.push(currNode->left);
                if(currNode->right != nullptr) q.push(currNode->right);
                lastNodeVal = currNode->val;
            }
            rightSide.push_back(lastNodeVal);
        }
        return rightSide;

    }
};