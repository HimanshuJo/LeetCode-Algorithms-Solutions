/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2025-02-23
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

    TreeNode* dfs(vector<int>&preorder, vector<int>&postorder, int preStart, int preEnd, int postStart){
        if(preStart>preEnd) return nullptr;
        if(preStart==preEnd){
            return new TreeNode(preorder[preStart]);
        }
        int currleftroot=preorder[preStart+1];
        int numNodesInLeftSide=1;
        while(postorder[postStart+numNodesInLeftSide-1]!=currleftroot){
            numNodesInLeftSide++;
        }
        TreeNode *root=new TreeNode(preorder[preStart]);
        root->left=dfs(preorder, postorder, preStart+1, preStart+numNodesInLeftSide, postStart);
        root->right=dfs(preorder, postorder, preStart+numNodesInLeftSide+1, preEnd, postStart+numNodesInLeftSide);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preStart=0, preEnd=preorder.size(), postStart=0;
        return dfs(preorder, postorder, preStart, preEnd-1, postStart);
    }
};

class Solution_O_N {
public:

    TreeNode* dfs(vector<int>&preorder, vector<int>&postorder, int preStart, int preEnd, int postStart, unordered_map<int, int>&mp){
        if(preStart>preEnd) return nullptr;
        if(preStart==preEnd){
            return new TreeNode(preorder[preStart]);
        }
        int currLeftRoot=preorder[preStart+1], numNodesInLeftSide=mp[currLeftRoot]-postStart+1;
        TreeNode *currRoot=new TreeNode(preorder[preStart]);
        currRoot->left=dfs(preorder, postorder, preStart+1, preStart+numNodesInLeftSide, postStart, mp);
        currRoot->right=dfs(preorder, postorder, preStart+numNodesInLeftSide+1, preEnd, postStart+numNodesInLeftSide, mp);
        return currRoot;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preStart=0, preEnd=preorder.size()-1, postStart=0;
        unordered_map<int, int>mp;
        for(int i=0; i<=preEnd; ++i){
            mp[postorder[i]]=i;
        }
        return dfs(preorder, postorder, preStart, preEnd, postStart, mp);
    }
};