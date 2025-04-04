/*
https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/?envType=daily-question&envId=2025-04-04
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

    TreeNode* bfs(TreeNode *root){
        if(root->left==nullptr&&root->right==nullptr) return root;
        queue<TreeNode*>q;
        unordered_map<TreeNode*, TreeNode*>parentMp;
        map<int, vector<TreeNode*>>maxDepthMp;
        q.push(root);
        parentMp[root]=nullptr;
        maxDepthMp[1].push_back(root);
        int curDepth=1;
        while(!q.empty()){
            int sz=q.size();
            curDepth++;
            while(sz--){
                auto curr=q.front();
                q.pop();
                if(curr->left!=nullptr){
                    q.push(curr->left);
                    parentMp[curr->left]=curr;
                    maxDepthMp[curDepth].push_back(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                    parentMp[curr->right]=curr;
                    maxDepthMp[curDepth].push_back(curr->right);
                }
            }
        }
        auto itr=maxDepthMp.rbegin();
        auto childrens=itr->second;
        auto frst=childrens[0];
        if(childrens.size()==1){
            return frst;
        }
        auto tochk=parentMp[frst];
        auto tempFrst=frst;
        while(true){
            auto currpar=parentMp[tempFrst];
            if(currpar==nullptr){
                break;
            }
            if(currpar->left!=nullptr&&currpar->right!=nullptr){
                bool gbflag=false;
                for(int i=0; i<childrens.size(); ++i){
                    auto tochk2=childrens[i];
                    bool flag=false;
                    while(true){
                        auto curpartochk2=parentMp[tochk2];
                        if(curpartochk2==nullptr) break;
                        if(curpartochk2==currpar){
                            flag=true;
                            break;
                        }
                        tochk2=curpartochk2;
                    }
                    if(!flag){
                        gbflag=true;
                    }
                }
                if(!gbflag)
                    return currpar;
            }
            tempFrst=currpar;
        }
        return root;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return bfs(root);
    }
};
