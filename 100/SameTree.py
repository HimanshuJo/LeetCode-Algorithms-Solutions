# https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:

        def dfs(node, ndlst):
            if node is None:
                return
            ndlst[0]=ndlst[0]+str(node.val)
            if node.left is None:
                ndlst[0]=ndlst[0]+"nulllft"
            else:
                dfs(node.left, ndlst)
            if node.right is None:
                ndlst[0]=ndlst[0]+"nullrght"
            else:
                dfs(node.right, ndlst)
            return

        def preOrderTrv(node, ndlst):
            dfs(node, ndlst)

        frst=[""]
        sec=[""]
        preOrderTrv(p, frst)
        preOrderTrv(q, sec)
        if frst[0]==sec[0]:
            return True
        return False