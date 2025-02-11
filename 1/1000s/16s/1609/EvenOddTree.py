# https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        
        def bfs(root):
            q=[]
            q.append(root)
            curlevel=0
            while(len(q)>=1):
                sz=len(q)
                prev=-1
                if curlevel%2!=0:
                    prev=sys.maxsize
                while(sz>=1):
                    curr=q[0]
                    del(q[0])
                    if curlevel%2!=0 and curr.val>=prev or curlevel%2!=0 and curr.val%2!=0 or curlevel%2==0 and curr.val<=prev or curlevel%2==0 and curr.val%2==0:
                        return False
                    prev=curr.val
                    if curr.left is not None:
                        q.append(curr.left)
                    if curr.right is not None:
                        q.append(curr.right)
                    sz-=1
                curlevel+=1
            return True
        
        return bfs(root)