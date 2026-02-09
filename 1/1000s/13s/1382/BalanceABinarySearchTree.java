/*
https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09
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

    public static TreeNode buildBalanceBTree(ArrayList<Integer>allNodesViaInorder, int left, int right){
        if(left>right) return null;
        int mid=left+(right-left)/2;
        TreeNode currentRoot=new TreeNode(allNodesViaInorder.get(mid));
        currentRoot.left=buildBalanceBTree(allNodesViaInorder, left, mid-1);
        currentRoot.right=buildBalanceBTree(allNodesViaInorder, mid+1, right);
        return currentRoot;
    }

    public static void performInorderTraversal(TreeNode root, ArrayList<Integer>allNodesViaInorder){
        if(root==null) return;
        performInorderTraversal(root.left, allNodesViaInorder);
        allNodesViaInorder.add(root.val);
        performInorderTraversal(root.right, allNodesViaInorder);
        return;
    }

    public TreeNode balanceBST(TreeNode root) {
        ArrayList<Integer>allNodesViaInorder=new ArrayList<>();
        performInorderTraversal(root, allNodesViaInorder);
        int left=0, right=allNodesViaInorder.size()-1;
        return buildBalanceBTree(allNodesViaInorder, left, right);
    }
}