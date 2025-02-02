/*
https://leetcode.com/problems/evaluate-boolean-binary-tree/description/?envType=daily-question&envId=2024-05-16
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

    public boolean depthFirstSearchTraversal_forTrees(TreeNode node){
        if(node.val==0) return false;
        if(node.val==1) return true;
        boolean leftTreeTraversalValueForCurrentNode=false, rightTreeTraversalValueForCurrentNode=false;
        if(node!=null){
            leftTreeTraversalValueForCurrentNode=depthFirstSearchTraversal_forTrees(node.left);
            rightTreeTraversalValueForCurrentNode=depthFirstSearchTraversal_forTrees(node.right);
            if(node.val==2){
                return leftTreeTraversalValueForCurrentNode||rightTreeTraversalValueForCurrentNode;
            } else{
                return leftTreeTraversalValueForCurrentNode&&rightTreeTraversalValueForCurrentNode;
            }
        }
        return false;
    }

    public boolean customPostOrderTraversal(TreeNode node){
        return depthFirstSearchTraversal_forTrees(node);
    }

    public boolean evaluateTree(TreeNode root) {
        if(root.val==0) return false;
        else if(root.val==1) return true;
        else{
            boolean leftTreeTraversalForRoot=customPostOrderTraversal(root.left);
            boolean rightTreeTraversalForRoot=customPostOrderTraversal(root.right);
            if(root.val==2) return leftTreeTraversalForRoot||rightTreeTraversalForRoot;
            return leftTreeTraversalForRoot&&rightTreeTraversalForRoot;
        }
    }
}