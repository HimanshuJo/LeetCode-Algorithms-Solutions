# https://leetcode.com/problems/evaluate-boolean-binary-tree/description/?envType=daily-question&envId=2024-05-16

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:

        def depthFirstSearchTraversal_forTrees(node):
            if node.val==0:
                return False
            if node.val==1:
                return True
            leftTreeTraversalValueForCurrentNode=False
            rightTreeTraversalValueForCurrentNode=False
            if node is not None:
                leftTreeTraversalValueForCurrentNode=depthFirstSearchTraversal_forTrees(node.left)
                rightTreeTraversalValueForCurrentNode=depthFirstSearchTraversal_forTrees(node.right)
                if node.val==2:
                    return leftTreeTraversalValueForCurrentNode or rightTreeTraversalValueForCurrentNode
                else:
                    return leftTreeTraversalValueForCurrentNode and rightTreeTraversalValueForCurrentNode
            return False

        def customPostOrderTraversal(node):
            return depthFirstSearchTraversal_forTrees(node)

        if root.val==0:
            return False
        elif root.val==1:
            return True
        else:
            leftTreeTraversalForRoot=customPostOrderTraversal(root.left)
            rightTreeTraversalForRoot=customPostOrderTraversal(root.right)
            if root.val==2:
                return leftTreeTraversalForRoot or rightTreeTraversalForRoot
            return leftTreeTraversalForRoot and rightTreeTraversalForRoot;