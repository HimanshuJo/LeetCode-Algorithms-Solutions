/*
https://leetcode.com/problems/binary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-25
*/

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

    void dfs(TreeNode *root, vector<int>&res){
        if(root==nullptr) return;
        dfs(root->left, res);
        dfs(root->right, res);
        if(root!=nullptr){
            res.push_back(root->val);
        }
        return;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        dfs(root, res);
        return res;
    }
};