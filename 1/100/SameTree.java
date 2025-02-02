/*
https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    public void dfs(TreeNode node, StringBuilder ndsbf){
        if(node==null) return;
        ndsbf.append(String.valueOf(node.val));
        if(node.left==null){
            ndsbf.append("nulllft");
        } else dfs(node.left, ndsbf);
        if(node.right==null){
            ndsbf.append("nullrght");
        } else dfs(node.right, ndsbf);
        return;
    }

    public void preOrderTrv(TreeNode node, StringBuilder ndsbf){
        dfs(node, ndsbf);
    }

    public boolean isSameTree(TreeNode p, TreeNode q) {
        StringBuilder frst=new StringBuilder("");
        StringBuilder sec=new StringBuilder("");
        preOrderTrv(p, frst);
        preOrderTrv(q, sec);
        return String.valueOf(frst).equals(String.valueOf(sec));

    }
}