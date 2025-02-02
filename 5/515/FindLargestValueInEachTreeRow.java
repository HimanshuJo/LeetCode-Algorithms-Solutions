/*
https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/?envType=daily-question&envId=2024-12-25
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

    public static List<Integer> breadthFirstSearch_forTrees(TreeNode root){
        List<Integer>resultantList=new ArrayList<>();
        LinkedList<TreeNode>queueOfTreeNodes=new LinkedList<>();
        queueOfTreeNodes.add(root);
        while(!queueOfTreeNodes.isEmpty()){
            int sizeOfQueue=queueOfTreeNodes.size(), currentMaxInRow=Integer.MIN_VALUE;
            while(sizeOfQueue-- >0){
                TreeNode currentNode=queueOfTreeNodes.pollFirst();
                int currentNodeValue=currentNode.val;
                currentMaxInRow=Math.max(currentMaxInRow, currentNodeValue);
                if(currentNode.left!=null){
                    queueOfTreeNodes.add(currentNode.left);
                }
                if(currentNode.right!=null){
                    queueOfTreeNodes.add(currentNode.right);
                }
            }
            resultantList.add(currentMaxInRow);
        }
        return resultantList;
    }

    public List<Integer> largestValues(TreeNode root) {
        if(root==null) return new ArrayList<>();
        return breadthFirstSearch_forTrees(root);
    }
}