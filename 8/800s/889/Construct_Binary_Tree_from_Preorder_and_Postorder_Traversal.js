/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2025-02-23
*/

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */

var depthFirstSearch_forTrees=function(preorder, postorder, preStart, preEnd, postStart, eleToIndexMapping){
    if(preStart>preEnd) return null;
    if(preStart==preEnd){
        return new TreeNode(preorder[preStart]);
    }
    let currLeftRoot=preorder[preStart+1], numNodesInLeftSide=eleToIndexMapping.get(currLeftRoot)-postStart+1;
    let currentRoot=new TreeNode(preorder[preStart]);
    currentRoot.left=depthFirstSearch_forTrees(preorder, postorder, preStart+1, preStart+numNodesInLeftSide, postStart, eleToIndexMapping);
    currentRoot.right=depthFirstSearch_forTrees(preorder, postorder, preStart+numNodesInLeftSide+1, preEnd, postStart+numNodesInLeftSide, eleToIndexMapping);
    return currentRoot;
}

var constructFromPrePost = function(preorder, postorder) {
    let preStart=0, preEnd=preorder.length-1, postStart=0;
    let eleToIndexMapping=new Map();
    for(let i=0; i<=preEnd; ++i){
        eleToIndexMapping.set(postorder[i], i);
    }
    return depthFirstSearch_forTrees(preorder, postorder, preStart, preEnd, postStart, eleToIndexMapping);
};