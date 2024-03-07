# https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        all=[]
        tmp=head
        anthtmp=head
        while(head is not None):
            all.append(head.val)
            head=head.next
        sz=len(all)
        count=sz//2
        while(count!=0):
            if anthtmp is None:
                break
            anthtmp=anthtmp.next
            count-=1
        return anthtmp