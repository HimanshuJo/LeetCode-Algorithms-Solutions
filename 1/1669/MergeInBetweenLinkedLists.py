# https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=daily-question&envId=2024-03-20

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        count=0
        diff=(b-a)+2
        tmplst1=list1
        res=tmplst1
        tmplst2=list1
        tmpl2lst2=list2
        while(count!=a-1):
            tmplst1=tmplst1.next
            tmplst2=tmplst2.next
            count+=1
        while(diff!=0):
            tmplst2=tmplst2.next
            diff-=1
        while(tmpl2lst2.next is not None):
            tmpl2lst2=tmpl2lst2.next
        tmpl2lst2.next=tmplst2
        tmplst1.next=list2
        return res