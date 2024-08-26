/*
https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26
*/

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {

    public static void depthFirstSearch_forTrees(Node root, List<Integer>resultantPostOrderTraversal){
        if(root==null) return;
        List<Node>currentChildren=root.children;
        int sizeOfChildren=currentChildren.size();
        for(int i=0; i<sizeOfChildren; ++i){
            Node currentChild=currentChildren.get(i);
            if(currentChild!=null){
                depthFirstSearch_forTrees(currentChild, resultantPostOrderTraversal);
            }
        }
        resultantPostOrderTraversal.add(root.val);
        return;
    }

    public List<Integer> postorder(Node root) {
        List<Integer>resultantPostOrderTraversal=new ArrayList<>();
        depthFirstSearch_forTrees(root, resultantPostOrderTraversal);
        return resultantPostOrderTraversal;
    }
}