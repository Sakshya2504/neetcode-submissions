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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "#,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return helper(data, index);
    }

    TreeNode* helper(string& data, int& index) {
        if (index >= data.size())
            return nullptr;

        // Extract one value
        string temp = "";

        while (data[index] != ',') {
            temp += data[index];
            index++;
        }

        index++; // skip ','

        // NULL node
        if (temp == "#")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(temp));

        root->left = helper(data, index);
        root->right = helper(data, index);

        return root;
    }
};
