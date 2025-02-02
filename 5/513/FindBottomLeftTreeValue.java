/*
https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=daily-question&envId=2024-02-28
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

    int bfs(TreeNode root){
        Deque<TreeNode>q=new LinkedList<>();
        q.add(root);
        TreeMap<Integer, ArrayList<TreeNode>>mp=new TreeMap<>();
        int curlevel=1;
        while(q.size()>=1){
            int sz=q.size();
            while(sz-- >0){
                TreeNode curr=q.pollFirst();
                if(curr.left==null&&curr.right==null){
                    if(mp.containsKey(curlevel)){
                        ArrayList<TreeNode>curarl=mp.get(curlevel);
                        curarl.add(curr);
                        mp.put(curlevel, curarl);
                    } else{
                        ArrayList<TreeNode>nw=new ArrayList<>();
                        nw.add(curr);
                        mp.put(curlevel, nw);
                    }
                }
                if(curr.left!=null) q.add(curr.left);
                if(curr.right!=null) q.add(curr.right);
            }
            curlevel++;
        }
        int res=-1;
        for(Map.Entry<Integer, ArrayList<TreeNode>>entry: mp.entrySet()){
            res=entry.getValue().get(0).val;
        }
        return res;
    }

    public int findBottomLeftValue(TreeNode root) {
        return bfs(root);
    }
}