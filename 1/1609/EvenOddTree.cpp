/*
https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29
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

    bool bfs(TreeNode *root){
        queue<TreeNode*>q;
        q.push(root);
        int curlevel=0;
        while(!q.empty()){
            int sz=q.size(), prev=-1;
            if(curlevel%2!=0) prev=INT_MAX;
            while(sz--){
                auto curr=q.front();
                q.pop();
                if(curlevel%2!=0&&(curr->val)>=prev||
                  (curlevel%2!=0&&(curr->val%2)!=0)||
                  (curlevel%2==0&&(curr->val)<=prev)||
                  (curlevel%2==0&&(curr->val%2)==0)) return false;
                prev=curr->val;
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }
            }
            curlevel++;
        }
        return true;
    }

    bool isEvenOddTree(TreeNode* root) {
        return bfs(root);
    }
};