/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        int countOfAllNodes=0, idx=0, pointer=0;
        ListNode tmp=head;
        while(tmp!=null){
            countOfAllNodes++;
            tmp=tmp.next;
        }
        idx=countOfAllNodes-n;
        if(pointer==idx){
            if(countOfAllNodes==1) return null;
            else return head.next;
        }
        ListNode fnres=head;
        while(fnres!=null){
            if(pointer+1==idx){
                ListNode curnextnext=fnres.next.next;
                fnres.next=curnextnext;
            }
            fnres=fnres.next;
            pointer++;
        }
        return head;
    }
}