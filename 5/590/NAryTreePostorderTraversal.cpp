/*
https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void dfs(Node *root, vector<int>&res){
        if(root==nullptr) return;
        for(auto &child: root->children){
            if(child!=nullptr){
                dfs(child, res);
            }
        }
        res.push_back(root->val);
        return;
    }

    vector<int> postorder(Node* root) {
        vector<int>res;
        dfs(root, res);
        return res;
    }
};