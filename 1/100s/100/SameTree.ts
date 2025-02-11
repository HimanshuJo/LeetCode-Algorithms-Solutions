/*
https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26
*/

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function dfs(node:TreeNode|null, ndlst:string[]):void{
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

function preOrderTrv(node:TreeNode|null, ndlst:string[]):void{
    dfs(node, ndlst);
}

function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
    let frst:string[]=[""], sec:string[]=[""];
    preOrderTrv(p, frst);
    preOrderTrv(q, sec);
    return frst[0]===sec[0];
};