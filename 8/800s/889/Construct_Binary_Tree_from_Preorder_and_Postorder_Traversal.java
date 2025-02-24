/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2025-02-23
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

    public static TreeNode depthFirstSearch_forTrees(int[] preorder, int[] postorder, int preStart, int preEnd, int postStart){
        if(preStart>preEnd) return null;
        if(preStart==preEnd){
            return new TreeNode(preorder[preStart]);
        }
        int currentLeftSubTreeNode=preorder[preStart+1], numNodesInLeftSide=1;
        while(postorder[postStart+numNodesInLeftSide-1]!=currentLeftSubTreeNode){
            numNodesInLeftSide++;
        }
        TreeNode currentRoot=new TreeNode(preorder[preStart]);
        currentRoot.left=depthFirstSearch_forTrees(preorder, postorder, preStart+1, preStart+numNodesInLeftSide, postStart);
        currentRoot.right=depthFirstSearch_forTrees(preorder, postorder, preStart+numNodesInLeftSide+1, preEnd, postStart+numNodesInLeftSide);
        return currentRoot;
    }

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        int preStart=0, preEnd=preorder.length-1, postStart=0;
        return depthFirstSearch_forTrees(preorder, postorder, preStart, preEnd, postStart);
    }
}