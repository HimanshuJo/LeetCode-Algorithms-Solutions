/*
https://leetcode.com/problems/reverse-linked-list/description/?envType=daily-question&envId=2024-03-21
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
    public ListNode ReverseList(ListNode head) {
        ListNode prev=null;
        while(head!=null){
            ListNode curnext=head.next;
            head.next=prev;
            prev=head;
            head=curnext;
        }
        return prev;
    }
}