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
    int helper(TreeNode* root){
        if(root == nullptr) return 0;
        // if(root->left != nullptr){
            int left = helper(root->left) + 1;
        // }
        // if(root->right != nullptr){
            int right = helper(root->right) + 1;
        // }
        return max(left, right);
    }
    int maxDepth(TreeNode* root) {
        int ans = helper(root);
        return ans;
    }
};
