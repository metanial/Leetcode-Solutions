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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> levelOrderVector;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> currLevel;
            for(int i=0; i<size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                currLevel.push_back(temp->val);
                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);
            }
            levelOrderVector.push_back(currLevel);
        }
        return levelOrderVector;
    }
};