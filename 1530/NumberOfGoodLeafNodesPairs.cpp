/*
https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/?envType=daily-question&envId=2024-07-18
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

    void dfs(TreeNode *curr, TreeNode *prev, map<TreeNode*, vector<TreeNode*>>&mp, set<TreeNode*>&leafNodes){
        if(curr==nullptr) return;
        if(curr->left==nullptr&&curr->right==nullptr){
            leafNodes.insert(curr);
        }
        if(prev!=nullptr){
            mp[curr].push_back(prev);
            mp[prev].push_back(curr);
        }
        dfs(curr->left, curr, mp, leafNodes);
        dfs(curr->right, curr, mp, leafNodes);
        return;
    }

    void postOrderTraversal(TreeNode *root, map<TreeNode*, vector<TreeNode*>>&mp, set<TreeNode*>&leafNodes){
        TreeNode *prev=nullptr;
        dfs(root, prev, mp, leafNodes);
    }

    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*, vector<TreeNode*>>mp;
        set<TreeNode*>leafNodes;
        postOrderTraversal(root, mp, leafNodes);
        int res=0;
        for(auto &leaf: leafNodes){
            queue<TreeNode*>q;
            q.push(leaf);
            set<TreeNode*>seen;
            seen.insert(leaf);
            for(int i=0; i<=distance; ++i){
                int sz=q.size();
                while(sz--){
                    auto curr=q.front();
                    q.pop();
                    if(curr->left==nullptr&&curr->right==nullptr&&curr!=leaf){
                        res++;
                    }
                    for(auto &nei: mp[curr]){
                        if(seen.find(nei)==seen.end()){
                            seen.insert(nei);
                            q.push(nei);
                        }
                    }
                }
            }
        }
        return res/2;
    }
};