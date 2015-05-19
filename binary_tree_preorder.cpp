// https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
// 
// Given a binary tree, return the preorder traversal of its values.


struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        visit(root, result);
        return result;
    }

    void visit(TreeNode *root, vector<int> &result) {
        if (root == 0)
            return;
        result.push_back(root->val);
        visit(root->left, result);
        visit(root->right, result);
    }
};
