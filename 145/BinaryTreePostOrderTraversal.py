# https://leetcode.com/problems/binary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-25

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        def depthFirstSearch_forTrees(root, resultantPostOrderList):
            if root is None:
                return
            depthFirstSearch_forTrees(root.left, resultantPostOrderList)
            depthFirstSearch_forTrees(root.right, resultantPostOrderList)
            if root is not None:
                resultantPostOrderList.append(root.val)
            return

        resultantPostOrderList=[]
        depthFirstSearch_forTrees(root, resultantPostOrderList)
        return resultantPostOrderList