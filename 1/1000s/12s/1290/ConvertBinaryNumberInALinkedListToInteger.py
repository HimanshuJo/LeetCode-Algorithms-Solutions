# https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?envType=daily-question&envId=2025-07-14

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:

        def toDecimal(headAsString):
            lengthOfStr=len(headAsString)
            finalDecimal=0
            beginPower=lengthOfStr-1
            for i in range(0, lengthOfStr, 1):
                finalDecimal+=int(headAsString[i])*(1<<beginPower)
                beginPower-=1
            return finalDecimal

        headAsString=""
        while(head!=None):
            headAsString+=str(head.val)
            head=head.next
        return toDecimal(headAsString)