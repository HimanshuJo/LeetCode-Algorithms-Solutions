# https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/submissions/1201407067/?envType=daily-question&envId=2024-03-12

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        alllst=[]
        while(head is not None):
            alllst.append(head.val)
            head=head.next
        sz=len(alllst)
        while(True):
            bgn=-1
            end=-1
            flag=False
            for i in range(0, sz, 1):
                cursm=0
                for j in range(i, sz, 1):
                    cursm+=alllst[j]
                    if cursm==0:
                        flag=True
                        bgn=i
                        end=j
                        break
                if flag==True:
                    break
            if flag==True:
                for i in range(bgn, end+1, 1):
                    alllst[i]=(sys.maxsize*-1)
                fnall=[x for x in alllst if x != (sys.maxsize*-1)]
                alllst=fnall
                sz=len(alllst)
            else:
                break
        if len(alllst)==0:
            return None
        res=ListNode(alllst[0])
        nxt=res
        for i in range(1, len(alllst), 1):
            nxt.next=ListNode(alllst[i])
            nxt=nxt.next
        return res