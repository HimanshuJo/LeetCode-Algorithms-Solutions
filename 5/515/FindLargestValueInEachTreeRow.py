# https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/?envType=daily-question&envId=2024-12-25

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:

        def breadthFirstSearch_forTrees(root):
            resultantList=[]
            queueOfTreeNodes=[]
            queueOfTreeNodes.append(root)
            while(len(queueOfTreeNodes)>0):
                sizeOfQueue=len(queueOfTreeNodes)
                currentMaxInRow=-2147483648
                while(True):
                    if sizeOfQueue==0:
                        break
                    currentNode=queueOfTreeNodes.pop(0)
                    currentNodeValue=currentNode.val
                    currentMaxInRow=max(currentMaxInRow, currentNodeValue)
                    if currentNode.left is not None:
                        queueOfTreeNodes.append(currentNode.left)
                    if currentNode.right is not None:
                        queueOfTreeNodes.append(currentNode.right)
                    sizeOfQueue-=1
                resultantList.append(currentMaxInRow)
            return resultantList

        if root is None:
            return []
        return breadthFirstSearch_forTrees(root)