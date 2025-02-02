/*
https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=daily-question&envId=2024-02-28
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

    int bfs(TreeNode *root){
        queue<TreeNode*>q;
        q.push(root);
        map<int, vector<TreeNode*>, greater<>>mp;
        int curlevel=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto curr=q.front();
                q.pop();
                if(curr->left==nullptr&&curr->right==nullptr){
                    mp[curlevel].push_back(curr);
                }
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }
            }
            curlevel++;
        }
        auto itr=mp.begin();
        return (itr->second[0])->val;
    }

    int findBottomLeftValue(TreeNode* root) {
        return bfs(root);
    }
};