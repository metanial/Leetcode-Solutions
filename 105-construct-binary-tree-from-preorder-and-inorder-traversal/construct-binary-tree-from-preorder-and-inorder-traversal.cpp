class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build a lookup: node value -> its index in inorder
        unordered_map<int,int> inIndex;
        for (int i = 0; i < (int)inorder.size(); i++) {
            inIndex[inorder[i]] = i;
        }

        // Kick off the recursion with full ranges of both arrays
        return build(preorder, 0, (int)preorder.size()-1,
                     inorder, 0, (int)inorder.size()-1,
                     inIndex);
    }

private:
    // Recursively builds the tree from the subarray ranges:
    // preorder[preStart..preEnd] and inorder[inStart..inEnd]
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder,  int inStart,  int inEnd,
                    unordered_map<int,int>& inIndex) {

        // Base case: no elements in this subtree
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        // Root of this subtree is the first element of the preorder slice
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Find root's position in inorder in O(1) using the map
        int inRoot = inIndex[rootVal];

        // Number of nodes in the left subtree (all nodes left of root in inorder)
        int leftSize = inRoot - inStart;

        // Build left subtree:
        //   - preorder slice: immediately after root, take leftSize elements
        //   - inorder slice: from inStart to inRoot-1
        root->left = build(preorder, preStart+1, preStart+leftSize,
                           inorder,  inStart,    inRoot-1,
                           inIndex);

        // Build right subtree:
        //   - preorder slice: skip root + leftSize, rest goes to right
        //   - inorder slice: from inRoot+1 to inEnd
        root->right = build(preorder, preStart+leftSize+1, preEnd,
                            inorder,  inRoot+1,            inEnd,
                            inIndex);

        // Return the constructed subtree
        return root;
    }
};
