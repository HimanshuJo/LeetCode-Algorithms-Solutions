/*
https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09
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

    TreeNode* buildBalanceBTree(vector<int>&vals, int left, int right){
        if(left>right) return nullptr;
        int mid=left+(right-left)/2;
        TreeNode *nwNode=new TreeNode(vals[mid]);
        nwNode->left=buildBalanceBTree(vals, left, mid-1);
        nwNode->right=buildBalanceBTree(vals, mid+1, right);
        return nwNode;
    }

    void inorder(TreeNode *root, vector<int>&vals){
        if(root==nullptr) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vals;
        inorder(root, vals);
        return buildBalanceBTree(vals, 0, vals.size()-1);
    }
};