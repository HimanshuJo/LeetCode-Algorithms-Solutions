# https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        all=[]
        fn=[]
        while(head is not None):
            all.append(head.val)
            head=head.next
        sec=[]
        sz=len(all)
        curcarry=0
        for i in range(0, sz, 1):
            sec.append(all[i])
        for i in range(sz-1, -1, -1):
            cursm=all[i]+sec[i]+curcarry
            if i>0:
                curcarry=cursm//10
                cursm%=10
            fn.append(cursm)
        fn.reverse()
        lntomk=""
        fnsz=len(fn)
        for i in range(0, fnsz, 1):
            lntomk+=str(fn[i])
        lntomklen=len(lntomk)
        root=ListNode(int(lntomk[0]))
        nxt=root
        for i in range(1, lntomklen, 1):
            nwNode=ListNode(int(lntomk[i]))
            nxt.next=nwNode
            nxt=nxt.next
        return root