/*
https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26
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

    void dfs(TreeNode *node, string &str){
        if(node==nullptr) return;
        str+=to_string(node->val);
        if(node->left==nullptr){
            str+="nulllft";
        } else dfs(node->left, str);
        if(node->right==nullptr){
            str+="nullrght";
        } else dfs(node->right, str);
        return;
    }

    void preOrderTrv(TreeNode *node, string &ndstr){
		dfs(node, ndstr);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        string frst="", sec="";
        preOrderTrv(p, frst);
        preOrderTrv(q, sec);
        return frst==sec;
    }
};