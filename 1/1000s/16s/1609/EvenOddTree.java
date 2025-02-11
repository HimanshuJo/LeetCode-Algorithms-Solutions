/*
https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29
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

    public boolean bfs(TreeNode root){
        Deque<TreeNode>dq=new LinkedList<>();
        dq.add(root);
        int curlevel=0;
        while(dq.size()>=1){
            int sz=dq.size(), prev=-1;
            if(curlevel%2!=0) prev=Integer.MAX_VALUE;
            while(sz-- >0){
                TreeNode curr=dq.pollFirst();
                if(curlevel%2!=0&&(curr.val)>=prev||
                  (curlevel%2!=0&&(curr.val%2)!=0)||
                  (curlevel%2==0&&(curr.val)<=prev)||
                  (curlevel%2==0&&(curr.val%2)==0)) return false;
                prev=curr.val;
                if(curr.left!=null){
                    dq.add(curr.left);
                }
                if(curr.right!=null){
                    dq.add(curr.right);
                }
            }
            curlevel++;
        }
        return true;
    }

    public boolean isEvenOddTree(TreeNode root) {
        return bfs(root);
    }
}