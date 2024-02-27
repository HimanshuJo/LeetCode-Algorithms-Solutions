/*
https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26
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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */

var dfs=function(node, ndlst){
    if(node===null) return;
    ndlst[0]+=(node.val).toString();
    if(node.left===null){
        ndlst[0]+="nulllft";
    } else dfs(node.left, ndlst);
    if(node.right===null){
        ndlst[0]+="nullrght";
    } else dfs(node.right, ndlst);
    return;
}

var preOrderTrv=function(node, ndlst){
    dfs(node, ndlst);
}

var isSameTree = function(p, q) {
    let frst=[""], sec=[""];
    preOrderTrv(p, frst);
    preOrderTrv(q, sec);
    return frst[0]===sec[0];
};