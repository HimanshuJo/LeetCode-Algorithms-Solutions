/*
https://leetcode.com/problems/evaluate-boolean-binary-tree/description/?envType=daily-question&envId=2024-05-16
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

    bool dfs(TreeNode *node){
        if(node->val==0) return false;
        if(node->val==1) return true;
        bool lft=false, rght=false;
        if(node!=nullptr){
            lft=dfs(node->left);
            rght=dfs(node->right);
            if(node->val==2){
                return lft||rght;
            } else{
                return lft&&rght;
            }
        }
        return false;
    }

    bool customPostOrder(TreeNode *node){
        return dfs(node);
    }

    bool evaluateTree(TreeNode* root) {
        if(root->val==0) return false;
        else if(root->val==1) return true;
        else{
            bool lft=customPostOrder(root->left);
            bool rght=customPostOrder(root->right);
            if(root->val==2) return lft||rght;
            else return lft&&rght;
        }
        return false;
    }
};